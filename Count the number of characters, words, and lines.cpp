#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int char_count = 0, word_count = 0, line_count = 0;
    char prev_char = ' ';

    printf("Enter text (press Ctrl+D to end input):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        line_count++;

        for (int i = 0; input[i] != '\0'; i++) {
            char_count++;

            if (isspace(input[i]) && !isspace(prev_char)) {
                word_count++;
            }

            prev_char = input[i];
        }
    }

    if (!isspace(prev_char)) {
        word_count++;
    }

    printf("\nNumber of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
}

