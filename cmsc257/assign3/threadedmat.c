#include <sys/times.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "base_matrix_functions.c"

#define MAX(a,b) (a < b ? b : a)
#define MIN(a,b) (a > b ? b : a)

double start, stop, used, mf;

double *mem;

double ftime(void);
void multiply (double **a, double **b, double **c, int n, int blocksize);

double ftime (void)
{
        struct tms t;

        times ( &t );

        return (t.tms_utime + t.tms_stime) / 100.0;
}

void multiply (double **a, double **b, double **c, int n, int blocksize)
{
        int i, j, k, i0, j0, k0, pid;

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)

                        c[i][j] = 0;
        }

        int step = MAX(1,n/blocksize);

        printf("\nBlock step size: %d\n", step);

        int forks = 0;

        for (i0 = 0; i0 < n; i0 += step) {
                for (j0 = 0; j0 < n; j0 += step) {
                        for (k0 = 0; k0 < n; k0 += step) {
                                forks++;
                                pid = fork();
                                if ( pid < 0 ) {
                                        fprintf(stderr,"fork failed at %d\n",i);
                                        exit(1);
                                } else if ( pid > 0 ) {
                                        // printf("parent: new child is %d\n",pid);
                                } else {
                                        for (i=i0; i < MIN(i0+step,n); i++) {
                                                for (j=j0; j < MIN(j0+step,n); j++) {
                                                        for (k=k0; k < MIN(k0+step,n); k++) {
                                                                // c[i][j]= 9;
                                                                c[i][j]= c[i][j] + a[i][k] * b[k][j];
                                                        }
                                                }
                                        }
                                        _exit(0);
                                }
                        }
                }
        }

        for ( i = 0; i < forks; i++ ) wait(NULL);
}

int main (int argc, char *argv[])
{
        int shmfd;

        time_t mytime;
        mytime = time(NULL);
        printf("Report began: %s\n\n", ctime(&mytime));

        // validate matrix multiplication
        // note because we are using shared memory, this is a bit different than the others
        struct validationMatrix *validator = buildSharedMemoryMatrix(mem);
        addValidationData(validator, 0);

        multiply(validator->a,validator->b,validator->c, 4, 2);

        validate(validator);

        int i, j, n;
        double **a, **b, **c;

        printf ("Testing large matrixes \n");
        printf ( "Enter the value of n: ");
        scanf ( "%d", &n);
        printf("%d", n);

        int blocksize = 1;

        // determine block size based on arg passed in originally
        // the argument passed in will divide `n` by either 1,2,4
        switch(*argv[1]) {
        case '1':
                blocksize = 1;
                break;
        case '2':
                blocksize = 2;
                break;
        case '4':
                blocksize = 4;
                break;
        default:
                blocksize = 1;
        }

        //Populate arrays....
        a= (double**)malloc(n*sizeof(double));
        b= (double**)malloc(n*sizeof(double));
        c= (double**)malloc(n*sizeof(double));

        /*
         * create shared memory for validation memory
         */
        shmfd = shm_open ( "/hernandez_shr2", O_RDWR | O_CREAT, 0666 );
        if ( shmfd < 0 ) {
                fprintf(stderr,"Could not create brs_memory\n");
                exit(1);
        }
        ftruncate (shmfd, n*n*3*sizeof(double));
        mem = (double *)mmap ( NULL, n*n*3*sizeof(double), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0 );
        if ( mem == NULL ) {
                fprintf(stderr,"Could not map brs_memory\n");
                exit(1);
        }
        close ( shmfd );
        shm_unlink ( "/hernandez_shr2" );

        for (i=0; i<n; i++)
        {
                a[i] = &mem[i];
                b[i] = &mem[i + (n*n)];
                c[i] = &mem[i + (n*n*2)];
        }

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)
                        a[i][j]=8;
        }

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)
                        b[i][j]=7;
        }

        start = ftime();
        multiply(a,b,c,n,blocksize);
        stop = ftime();
        used = stop - start;
        mf = (n*n*n *2.0) / used / 1000000.0;
        printf ("\n");
        printf ( "Elapsed time:   %10.2f \n", used);
        printf ( "DP MFLOPS:       %10.2f \n", mf);

        mytime = time(NULL);
        printf("\n\nReport completed: %s\n", ctime(&mytime));
        return (0);
}
