#include <stdio.h>

/*  function declarations  */
void matrixMult(int [3][3], int [3][3], int [3][3]);
void printMatrix(int [3][3]);

int main (void)
{
    int i, j, x;
    int matrixA[3][3] = {{1, 2, 5},
                         {9, 8, 7},
                         {3, 4, 6}}; 
    int matrixB[3][3] = {{1, 3, 4},
                         {8, 6, 5}, 
                         {7, 7, 2}}; 
    int matrixC[3][3];

    /* initialize matrixC */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            matrixC[i][j] = 0;  /* could have used *(*(matrixC + i) + j) */
        }

    matrixMult(matrixA, matrixB, matrixC);

    printMatrix(matrixA);
    printf("\n");
    printMatrix(matrixB);
    printf("\n");
    printMatrix(matrixC);
    printf("\n");
}

/*  function definitions  */
void matrixMult(int X[3][3], int Y[3][3], int Z[3][3])
{
    int i, j, k;
    for (i = 0; i < 3; i++)      /* rows */
    {
        for (j = 0; j < 3; j++)  /* columns */
        {
            for (k = 0; k < 3; k++)
            {
                /*  perform matrix multiplication  */
                Z[i][j] += X[i][k] * Y[k][j];
                /* this is equivalent to using
                   *(*(Z + i) + j) += *(*(X + i) + k) * *(*(Y + k) + j); 
                */
            }
        }
    }
}

void printMatrix(int matrix[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d ", *(*(matrix + i) + j));
        printf("\n");
    }
}

/*************************************************************
*************************   Output   *************************

  1   2   5
  9   8   7
  3   4   6

  1   3   4
  8   6   5
  7   7   2

 52  50  24
122 124  90
 77  75  44

*/

