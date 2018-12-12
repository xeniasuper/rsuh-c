#include <stdio.h>
#include <stdlib.h>
#include "int_arr_lib.h"

int **ReflectMatrix (int n_rows, int n_cols, int **matrix)
{
    int **reflected = Malloc2dInt(n_cols, n_rows);
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            reflected[j][i] = matrix[i][j];
        }
    }
    return reflected;
}

int main()
{
    int n_rows, n_cols;
    printf("Enter number of rows: ");
    scanf("\n");
    scanf("%d", &n_rows);
    printf("Enter number of columns: ");
    scanf("%d", &n_cols);

   int **matrix = Malloc2dInt(n_rows, n_cols);
   printf("Enter the matrix by element:\n");
   Scan2dInt(n_rows, n_cols, matrix);
    Print2dInt(n_rows, n_cols, matrix);
   matrix = ReflectMatrix(n_rows, n_cols, matrix);

   Print2dInt(n_cols, n_rows, matrix);
   Free2dInt(n_rows, n_cols, matrix);

   return 0;
}