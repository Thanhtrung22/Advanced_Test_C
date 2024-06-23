#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 105

void allocate(uint16_t** arr)
{
    *arr = (uint16_t*)malloc(sizeof(uint16_t) * SIZE);
}

void Free(uint16_t* arr)
{
    free(arr);
    printf("\nFree memory successfull");
}

int main()
{
    uint16_t* arr = NULL;
    allocate(&arr);
    if(arr == NULL)
    {
        printf("\nError allocating memory");
        return -1;
    }
    printf("\nAllocating memory successfull");
    for(uint8_t i = 0; i < SIZE; i++)
    {
        arr[i] = 0;
    }
    printf("\n%u", arr[0]);
    Free(arr);
    arr = NULL;
    return 0;


}