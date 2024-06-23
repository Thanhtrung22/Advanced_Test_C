#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t a = 9;
    uint8_t* p_a = &a;

    double b;
    scanf("%lf", &b);
    printf("%.15g", b);
    printf("\n%hhu", *p_a );
}