#include "int_arr_lib.h"
#include <stdio.h>
#include <stdlib.h>

// allocates memory for a 2-dim array of integers
// DOES NOT FREE MEMORY! USE Free2dInt() !!!
int ** Malloc2dInt (int n_rows, int n_cols)
{
    int **matrix = (int **)malloc(n_rows * sizeof(int *));
    if (NULL == matrix) exit(1);

    for (int i = 0; i < n_rows; i++)
    {
        matrix[i] = (int *)malloc(n_cols * sizeof(int));
        if (NULL == matrix[i]) exit(1);
    }
    return matrix;
}

// frees memory from 2-dim array of integers
void Free2dInt(int n_rows, int n_cols, int **matrix)
{
    for (int i = 0; i < n_rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// scans 2-dim array of integers
void Scan2dInt (int n_rows, int n_cols, int **matrix)
{
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// prints 2-dim array of integers
void Print2dInt (int n_rows, int n_cols, int **matrix)
{
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
