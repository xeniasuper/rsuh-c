#include <stdio.h>
#include <stdlib.h>

// удалить все пробелы в строке

void PrintStr(size_t len_str, char* str);

void DelSpaces(size_t len_str, const char* str, int *len_no_spaces, char *no_spaces);

int main()
{
    size_t len_str;
    printf("Enter the length:\n");
    scanf("%zd", &len_str);
    len_str++;
    //printf("%zd", len_str-1);
    char *str = (char *)malloc(len_str * sizeof(char));

    printf("Enter the string:\n");
    fgets(str, 2, stdin);
    fgets(str, len_str, stdin);

    char *no_spaces = (char *)malloc(sizeof(char));
    if (no_spaces == NULL) exit(1);

    int len_no_spaces = 0;
    int *ptr_len_no_spaces = & len_no_spaces;
    DelSpaces(len_str, str, ptr_len_no_spaces, no_spaces);

    PrintStr(len_no_spaces, no_spaces);

    free(str);
    free(no_spaces);
    return 0;
}

void PrintStr(size_t len_str, char* str)
{
    len_str--;

    for (int i = 0; i < len_str; i++)
    {
        printf("%c", str[i]);
    }
}

void DelSpaces(size_t len_str, const char* str, int *len_no_spaces, char *no_spaces)
{

    for (int i = 0; i < len_str; i++)
    {
        if (str[i] != ' ')
        {
            no_spaces[* len_no_spaces] = str[i];
            ++ * len_no_spaces;
        }
    }
}