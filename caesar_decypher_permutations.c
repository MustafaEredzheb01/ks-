#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1024
#define ALPHABET_SIZE 26

char* caesar_decipher(char* cypher, int key) {
    int length = strlen(cypher);
    char* result = (char*)malloc(length + 1);

    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; cypher[i] != '\0'; i++) {
        char c = cypher[i];
        if (c >= 'A' && c <= 'Z') {
            result[i] = ((c - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            result[i] = ((c - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'a';
        } else {
            result[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    result[length] = '\0';

    return result;
}

int main() {
    char cypher[MAXN];
    if (scanf("%s", cypher) != 1) {
        printf("Error reading cypher text\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char* text = caesar_decipher(cypher, i);
        printf("Key %d, message: %s\n", i, text);
        free(text);
    }

    return EXIT_SUCCESS;
}
