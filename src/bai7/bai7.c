#include <stdio.h>

int main()
{
    char input[101];
    char name[31];
    char id[9];
    char class[10];
    char generation[4];
    double gpa;

    scanf("%[^\n]", input);
    sscanf(input, "%[^,],%[^,],%[^,],%[^,],%lf", name, id, class, generation,&gpa);
    printf("\n%s", name);
    printf("\n%s", id);
    printf("\n%s", class);
    printf("\n%s", generation);
    printf("\n%.2f", gpa);
    return 0;
}