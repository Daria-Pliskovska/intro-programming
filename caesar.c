#include <stdio.h>
#include <ctype.h>

int main(void) {
    int count;
    int key;
    int entered = 0;

    printf("Enter the number of characters to encrypt: ");

    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid input: must be a positive integer\n");
        return 1;
    }

    printf("Enter encryption key [-128, 127]: ");

    if (scanf("%d", &key) != 1 || key < -128 || key > 127) {
        printf("Invalid input: key must be in range [-128, 127]\n");
        return 1;
    }

    while (entered < count) {
        char symbol;
        char letter;
        int position;

        printf("Enter character %d: ", entered + 1);
        scanf(" %c", &symbol);

        if (!isalpha(symbol)) {
            printf("Invalid input: must be a valid alphabetic character\n");
            continue;
        }

        letter = tolower(symbol);
        position = (letter - 'a' + key) % 26;

        if (position < 0) {
            position += 26;
        }

        printf("Encrypted character: %c\n", 'a' + position);
        ++entered;
    }

    return 0;
}
