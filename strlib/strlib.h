#ifndef STRLIB_LIBRARY_H
#define STRLIB_LIBRARY_H

int CountWords (char *arr, int len_arr);
char ** Malloc2dChar (int len_arr, int len_elem);
void Free2dChar (char **arr, int len_arr);
void Split (char *arr, int len_arr, char **split);
void Print2dChar (char **arr, int len_arr);

#endif