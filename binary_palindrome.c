#include <stdio.h>

int main(void) {
    int number;
    int rest;
    int reversed = 0;

    printf("Enter an integer: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input: must be an integer\n");
        return 1;
    }

    if (number < 0) {
        printf("Invalid input: must be a non-negative integer\n");
        return 1;
    }

    rest = number;

    while (rest > 0) {
        reversed = reversed * 2 + rest % 2;
        rest /= 2;
    }

    if (reversed == number) {
        printf("%d is a binary palindrome\n", number);
    } else {
        printf("%d is not a binary palindrome\n", number);
    }

    return 0;
}
