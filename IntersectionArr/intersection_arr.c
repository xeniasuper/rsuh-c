#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// записать в массив С элементы из А которые есть в В

void ScanArray(const int array_size, const int *array);
void PrintArray(const int array_size, const int *array);
bool IsInArray(const int elem, const int* array, const int array_size);
void IntersectTwoArrays(int len_arr1, int *arr1, int len_arr2, int *arr2,  int * ptr_len_intersection, int *intersection);

int main()
{
    int len_arr1;
    printf("Enter the length of the 1st array: ");
    scanf("%d", &len_arr1);
    printf("\n");
    int *arr1 = (int *)malloc(len_arr1 * sizeof(int));
    printf("Enter the elements of the array: ");
    ScanArray(len_arr1, arr1);
    printf("\n");

    int len_arr2;
    printf("Enter the length of the 2nd array: ");
    scanf("%d", &len_arr2);
    printf("\n");
    int *arr2 = (int *)malloc(len_arr2 * sizeof(int));
    printf("Enter the elements of the array: ");
    ScanArray(len_arr2, arr2);

    int *intersection = (int *)malloc(sizeof(int));
    if (intersection == NULL) exit (1);
    int len_intersection = 0;
    int * ptr_len_intersection = &len_intersection;

    IntersectTwoArrays(len_arr1, arr1, len_arr2, arr2, ptr_len_intersection, intersection);
    PrintArray(len_intersection, intersection);

    free(arr1);
    free(arr2);
    free(intersection);

    return 0;
}

void ScanArray(const int array_size, const int *array)
{
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void PrintArray(const int array_size, const int *array)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
}


bool IsInArray(const int elem, const int* array, const int array_size)
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

void IntersectTwoArrays(int len_arr1, int *arr1, int len_arr2, int *arr2,  int * ptr_len_intersection, int *intersection)
{
    int idx_intersection = 0; // в элемент массива с с этим индексом кладем нужный элемент из а
    for (int i = 0; i < len_arr1; i++)
    {
        if (IsInArray(arr1[i], arr2, len_arr2))
        {
            intersection[idx_intersection] = arr1[i];
            ++idx_intersection;
            ++ * ptr_len_intersection;
        }
    }
}