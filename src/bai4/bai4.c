#include <stdio.h>
#include <stdlib.h>


#define SIZE_NAME 31
typedef struct
{
    int grade;
    double height;
    char* name;
}student;

int get_number(const char* mess)
{
    int number = 0;
    int check_number = 0;
    do
    {
        printf("\n%s: ", mess);
        check_number = scanf("%d", &number);
        while(getchar() != '\n');
        printf("\nGia tri nhan duoc: %d", number);
    }while(!check_number || number <= 0);
    return number;
}

void allocate(student **stu, int n)
{
    *stu = (student*)malloc((unsigned)n * sizeof(student));
    if(*stu == NULL)
    {
        printf("\nError: cannot allocate");
        return;
    }
    for(int i = 0; i < n; i++)
    {
        (*stu)[i].name = (char*)malloc(sizeof(char) * SIZE_NAME);
        if((*stu)[i].name == NULL)
        {
            printf("\nError: cannot allocate");
            return;
        } 
    }
}

void Free(student *stu, int n)
{
    for(int i = 0; i < n; i++)
    {
        free((stu)[i].name);
    }
    free(stu);
    printf("\nFree succeeded");
}

void get_inform_student(student *stu, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\nNhap khoi lop: ");
        scanf("%d", &stu[i].grade);
        while(stu[i].grade <= 0 || stu[i].grade > 12)
        {
            printf("\nVui long nhap lai khoi lop: (1 -12)");
            scanf("%d", &stu[i].grade);

        }
        printf("\nChieu cao: ");
        scanf("%lf", &stu[i].height);
        while(getchar() != '\n');
        printf("\nTen: ");
        scanf("%[^\n]", stu[i].name);
    }
}
void display(student *stu, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\nSinh vien thu %d: ", i + 1);
        printf("\nKhoi lop: %d", stu[i].grade);
        printf("\nChieu cao: %g", stu[i].height);
        printf("\nTen: %s", stu[i].name);
    }
}
int main()
{
    int n = 0;
    student *list = NULL;
    n = get_number("Nhap so sinh vien");
    allocate(&list, n);
    get_inform_student(list, n);
    display(list, n);
    Free(list, n);
    return 0;

}