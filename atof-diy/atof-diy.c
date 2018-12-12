// перобразовать строку в число с плавающей точкой
// принципат октавиана августа
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Pow(int x, int y)
{
    int res = 1;
    for (int i = 0; i < y; i++)
    {
        res *= x;
    }
    return res;
}

double MyAtof (const char *str)
{
    double res = 0;
    int point_pos = 0;
    bool point_found = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '.'){
            if (point_found == 1) point_pos++;
            res = res*10 + str[i]-'0';
        }
        else
        {
            point_found = 1;
        }
    }
    res = res / Pow(10, point_pos);
    return res;
}

int main()
{
    printf("Enter the string length and then the string: ");
    size_t len_str;
    scanf("%zd ", &len_str);
    len_str++; // т.к. fgets в len_str учитывает символ конца строки

    char* str = (char *)malloc(len_str * sizeof(char));
    fgets(str, len_str, stdin);

    double res = MyAtof(str);
    printf("%f", res);
    return 0;
}