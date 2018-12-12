#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void ScanArray(size_t array_size, int *array);

void PrintArray(size_t array_size, int *array);

// checks whether an element is in an array
bool IsInArray(int elem, size_t array_size, int *array);

void FillNoDuplicates(size_t array_size, int *array, size_t *ptr_size_no_dupl, int *no_duplicates);

int main()
{

    size_t array_size;
    printf("Enter the size of the array and then the elements: ");
    scanf("%zd", &array_size);

    int *array = (int *)malloc(array_size * sizeof(int));
    ScanArray(array_size, array);

    int *no_duplicates = (int *)malloc(sizeof(int));
    if (no_duplicates == NULL) exit (1);

    size_t size_no_duplicates = 0;
    size_t *ptr_size_no_dupl = &size_no_duplicates;

    FillNoDuplicates(array_size, array, ptr_size_no_dupl, no_duplicates);
    PrintArray(size_no_duplicates, no_duplicates);

    free(array);
    free(no_duplicates);

    return 0;
}

void PrintArray(size_t array_size, int *array)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
}

void ScanArray(size_t array_size, int *array)
{
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

bool IsInArray(int elem, size_t array_size, int *array)
{
    bool flag = false;

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == elem)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

void FillNoDuplicates(size_t array_size, int *array, size_t *ptr_size_no_dupl, int *no_duplicates)
{
    for (int i = 0; i < array_size; i++)
    {
        if (! IsInArray(array[i], * ptr_size_no_dupl, no_duplicates))
        {
            size_t idx = * ptr_size_no_dupl;
            no_duplicates[idx] = array[i];
            ++ * ptr_size_no_dupl;
        }
    }
}