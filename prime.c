#include <stdio.h>

int main(void) {
    int number;
    int is_prime = 1;

    printf("Enter an integer: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input: must be an integer\n");
        return 1;
    }

    if (number < 2) {
        is_prime = 0;
    }

    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            is_prime = 0;
            break;
        }
    }

    if (is_prime) {
        printf("%d is a prime number\n", number);
    } else {
        printf("%d is not a prime number\n", number);
    }

    return 0;
}
