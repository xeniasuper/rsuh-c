#ifndef INT_ARR_LIB_LIBRARY_H
#define INT_ARR_LIB_LIBRARY_H

int ** Malloc2dInt (int n_rows, int n_cols);
void Free2dInt(int n_rows, int n_cols, int **matrix);
void Scan2dInt (int n_rows, int n_cols, int **matrix);
void Print2dInt (int n_rows, int n_cols, int **matrix);

#endif