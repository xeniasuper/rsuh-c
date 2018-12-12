// заполнить матрицу n*m улиткой
#include <stdio.h>
#include <stdlib.h>

void PrintTwoDimArr(int n_rows, int n_cols, int **arr);
void FillSnail(int n_rows, int n_cols, int **arr);

int main()
{
    int n_rows;
    printf("Enter number of rows and number of columns: ");
    scanf("%d", &n_rows);
    int n_cols;
    scanf("%d", &n_cols);

    if(n_rows == 0 || n_cols == 0)
    {
        printf("Number of rows must be greater than zero.");
        exit(1);
    }

    int **matrix = (int **)malloc(n_rows * sizeof(int *));
    for (int i = 0; i < n_rows; i++)
    {
        matrix[i] = (int *)malloc(n_cols * sizeof(int));
    }
    FillSnail(n_rows, n_cols, matrix);

    PrintTwoDimArr(n_rows, n_cols, matrix);

    for (int i = 0; i < n_rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

void PrintTwoDimArr(int n_rows, int n_cols, int **arr)
{
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_cols; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

void FillSnail(int n_rows, int n_cols, int **arr)
{
    int start_row = 0;
    int stop_row = n_rows-1;
    int start_col = 0;
    int stop_col = n_cols-1;
    int value = 1;

    while (start_col <= stop_col && start_row <= stop_row)
    {
        for (int i = start_col; i <= stop_col; i++)
        {
            arr[start_row][i] = value;
            value++;
        }
        start_row++;

        for (int i = start_row; i <= stop_row; i++)
        {
            arr[i][stop_col] = value;
            value++;
        }
        stop_col--;

        if (start_row <= stop_row)
        {
            for (int i = stop_col; i >= start_col; i--)
            {
                arr[stop_row][i] = value;
                value++;
            }
            stop_row--;
        }

        if (start_col <= stop_col)
        {
            for (int i = stop_row; i >= start_row; i--)
            {
                arr[i][start_col] = value;
                value++;
            }
            start_col++;
        }

    }

}