#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    while (true) {
        char letter;
        printf("Enter a letter: ");

        if (scanf(" %c", &letter) != 1 || !isalpha(letter)) {
            printf("Invalid input. Stopping...\n");
            break;
        }

        letter = tolower(letter);
        printf("The letter %c is at position %d in the alphabet.\n", letter, letter - 'a' + 1);
    }

    return 0;
}
