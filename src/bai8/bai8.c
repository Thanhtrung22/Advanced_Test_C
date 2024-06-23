#include <stdio.h>

typedef struct
{
    double real;
    double imag;
}complex;

void display_complex(complex num, const char *mess)
{
    printf("\n%s: %g + %gi", mess, num.real, num.imag);
}
int main()
{
    char input[2001];
    char req[11];
    complex num1 = {0, 0}, num2 = {0, 0};
    printf("\nNhap input: ");
    scanf("%[^\n]", input);
    sscanf(input, "{request:%[^,],value:{%lf + %lfi,%lf + %lfi}}", req, &num1.real, &num1.imag, &num2.real, &num2.imag);
    printf("\nYeu cau: %s", req);
    display_complex(num1,"So phuc 1");
    display_complex(num2,"So phuc 2");
    return 0;
}