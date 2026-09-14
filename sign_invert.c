#include <stdio.h>

union FloatBits {
    float f;
    unsigned int u;
};

int main(void) {
    union FloatBits value;

    printf("Enter a float number: ");
    if (scanf("%f", &value.f) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    value.u ^= 0x80000000u;

    printf("Float with reversed sign: %.3f\n", value.f);

    return 0;
}