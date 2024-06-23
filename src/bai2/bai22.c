#include <stdio.h>
#include <stdlib.h>


void allocate(double **arr, int n)
{
    *arr = (double *) malloc((unsigned) n * sizeof(double));
}

void Free(double *arr)
{
    free(arr);
    printf("\nFree succeeded\n");
}

int get_input_num(char *mess)
{
    int check_num = 0;
    int n = 0;
    do
    {
        printf("\n%s: ", mess);
        check_num = scanf("%d", &n);
        while(getchar() != '\n');
        printf("\nGia tri nhan duoc: %d", n);

    }while(!check_num || n <= 0);
    return n;
}

int main()
{
    double *arr = NULL; // nên để là double để tránh warning khi tính với số nguyên
    int n = 0;

    n = get_input_num("Nhap so phan tu mang");
    allocate(&arr, n);
    if(arr == NULL)
    {
        printf("\nError allocating memory");
        return -1;
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] =  i + 1;
    }
    for(int i = 0; i < n; i++)
    {
        printf("\n%.3f", arr[i]);
    }
    Free(arr);
    arr = NULL;
    return 0;

}