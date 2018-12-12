// преобразовать строку в целое число
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int my_atoi (const char *str)
{
  int num = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
      num = num*10 + str[i]-'0';
  }
  return num;
}

int main()
{
    printf("Enter the string length and then the string: ");
    size_t len_s;
    scanf("%zd ", &len_s);
    len_s++;

    char* str = (char *)malloc(len_s * sizeof(char));
    fgets(str, len_s, stdin);

    int value = my_atoi(str);
    printf("%d", value);

    free(str);
    return 0;
}