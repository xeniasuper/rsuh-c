#include "strlib.h"

#include <stdio.h>
#include <stdlib.h>


// counts number of words in a string
int CountWords (char *arr, int len_arr) {
    int cnt_words = 1;
    for (int i = 0; i < len_arr; i++)
    {
        if (arr[i] == ' ') cnt_words++;
    }
    return cnt_words;
}

// allocates memory for 2-dimensional array of chars
// DOES NOT FREE MEMORY!!! Use Free2dChar() !!!
char ** Malloc2dChar (int len_arr, int len_elem)
{
    char **arr = (char **)malloc(len_arr * sizeof(char *));
    if (arr == NULL) exit(1);
    for (int i = 0; i < len_arr; i++)
    {
        arr[i] = (char *)malloc(len_elem * sizeof(char));
        if (arr[i] == NULL) exit(1);
    }
    return arr;
}

//  frees memory from 2-dimensional array of chars
void Free2dChar (char **arr, int len_arr)
{
    for (int i = 0; i < len_arr; i++)
        free(arr[i]);
    free(arr);
}

// splits a string into words;
// returns void, so you should create array for split string beforehand
void Split (char *arr, int len_arr, char **split)
{
    int cnt_words = 1;
    int cnt_symb = 0;
    for (int i = 0; i < len_arr - 1; i++)
    {
        if (arr[i] != ' ')
        {
            split[cnt_words-1][cnt_symb] = arr[i];
            cnt_symb++;
        }
        else
        {
            split[cnt_words-1][cnt_symb] = '\0';
            cnt_words++;
            cnt_symb = 0;
        }
    }
}

// prints a 2-dimensional array of chars
void Print2dChar (char **arr, int len_arr) {
    for (int i = 0; i < len_arr; i++)
        printf("%s\n", arr[i]);
}
