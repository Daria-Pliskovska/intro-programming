#include <stdio.h>

int main(void) {
    int number;
    unsigned int bits;
    unsigned int reversed = 0;
    int width;
    int i;

    printf("Enter an integer: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input: must be an integer\n");
        return 1;
    }

    bits = (unsigned int)number;

    if (number < 0) {
        width = 32;
    } else {
        width = 1;

        while ((bits >> width) != 0) {
            ++width;
        }
    }

    for (i = 0; i < width; ++i) {
        reversed = (reversed << 1) | ((bits >> i) & 1u);
    }

    if (reversed == bits) {
        printf("%d is a binary palindrome\n", number);
    } else {
        printf("%d is not a binary palindrome\n", number);
    }

    return 0;
}
