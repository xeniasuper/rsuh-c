// найти все вхождения str2 в str1
#include <stdio.h>
#include <stdlib.h>

int Count (char s1[], int len_s1, char s2[], int len_s2)
{
    int same_chars = 0;
    int substrings = 0;
    int j = 0;

    for (int i = 0; i < len_s1 - 1; i++)
    {
        if (s1[i] == s2[j]) {
            same_chars++;
            ++j;
        }
        else
        {
            same_chars = 0;
            j = 0;
        }

        if(same_chars == len_s2-1){
            substrings++;
            j = 0;
            same_chars = 0;
        }

    }

    return substrings;
}

int main()
{

    int len_str1;
    printf("Enter number of symbols of the string and the string: ");
    scanf("%d ", &len_str1);
    len_str1++;

    char *str1 = (char *)malloc(len_str1 * sizeof(char));
    fgets(str1, len_str1, stdin);

    int len_str2;
    printf("Enter number of symbols of the string and the string: ");
    scanf("%d ", &len_str2);
    len_str2++;

    char *str2 = (char *)malloc(len_str2 * sizeof(char));
    fgets(str2, len_str2, stdin);

    printf("%d", Count(str1, len_str1, str2, len_str2));
    free(str1);
    free(str2);
    return 0;
}