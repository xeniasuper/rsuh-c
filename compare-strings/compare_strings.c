#include <stdio.h>
#include <stdlib.h>

int CompareStrings (const char* str1, const size_t len_str1, const char* str2, const size_t len_str2);
// DOES NOT FREE MEMORY!!!

int Min(int a, int b);

int main()
{
    size_t len_s1;
    size_t len_s2;
    printf("Enter the length of the 1st string, then the length of the 2nd string and then two strings: ");
    scanf("%zd ", &len_s1);
    scanf("%zd ", &len_s2);
    scanf(" ");
    len_s1++;
    len_s2++;

    char* s1 = (char *)malloc(len_s1 * sizeof(char));
    char* s2 = (char *)malloc(len_s1 * sizeof(char));
    fgets(s1, len_s1+1, stdin);
    scanf(" ");
    fgets(s2, len_s2, stdin);

    int res = CompareStrings(s1, len_s1, s2, len_s2);
    if (res == -1) printf("s1 is greater than s2");
    else printf("s2 is greater than s1");

    free(s1);
    free(s2);
    return 0;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

int CompareStrings (const char* str1, const size_t len_str1, const char* str2, const size_t len_str2)
{
    int res;

    size_t len = Min(len_str1, len_str2);

    for (int i = 0; i < len; i++)
    {
        if (str1[i] > str2[i])
        {
            res = -1;
            break;
        }
        else if (str1[i] < str2[i])
        {
            res = 1;
            break;
        }
        else
            {
                if (i == len_str1-1) res = -1;
            }
    }
    return res;
}