#include <sys/times.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "base_matrix_functions.c"

double start, stop, used, mf;

double ftime(void);
void multiply (double **a, double **b, double **c, int n);

double ftime (void)
{
        struct tms t;

        times ( &t );

        return (t.tms_utime + t.tms_stime) / 100.0;
}

void multiply (double **a, double **b, double **c, int n)
{
        int i, j, k;

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)

                        c[i][j] = 0;
        }

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)
                {
                        for (k=0; k<n; k++)
                                c[i][j]= c[i][j] + a[i][k] * b[j][k];
                }
        }
}

int main (void)
{
        time_t mytime;
        mytime = time(NULL);
        printf("Report began: %s\n\n", ctime(&mytime));

        // validate matrix multiplication
        struct validationMatrix * validator = buildValidationMatrix(1);

        multiply(validator->a,validator->b,validator->c, 4);

        validate(validator);

        int i, j, n;
        double **a, **b, **c;

        printf ( "Enter the value of n: ");
        scanf ( "%d", &n);
        printf("%d", n);

        //Populate arrays....
        a= (double**)malloc(n*sizeof(double));
        b= (double**)malloc(n*sizeof(double));
        c= (double**)malloc(n*sizeof(double));

        for (i=0; i<n; i++)
        {
                a[i]= malloc(sizeof(double)*n);
                b[i]= malloc(sizeof(double)*n);
                c[i]= malloc(sizeof(double)*n);
        }

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)
                        a[i][j]=8;
        }

        for (i=0; i<n; i++)
        {
                for (j=0; j<n; j++)
                        // store in the transpose
                        b[j][i]=7;
        }

        start = ftime();
        multiply (a,b,c,n);
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
