#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

char* caesar_cypher(char* str, int key) {
    int length = strlen(str);
    char* cypher = (char*)malloc(length + 1);

    if (cypher == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (isupper(c)) {
            cypher[i] = ((c - 'A' + key) % ALPHABET_SIZE) + 'A';
        } else if (islower(c)) {
            cypher[i] = ((c - 'a' + key) % ALPHABET_SIZE) + 'a';
        } else {
            cypher[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    cypher[length] = '\0';

    return cypher;
}

int main() {
    const int MAXN = 1000;
    char str[MAXN];
    printf("Enter text: ");
    if (scanf("%s", str) != 1) {
        printf("Error reading text\n");
        return EXIT_FAILURE;
    }

    int key;
    printf("Enter key: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid key\n");
        return EXIT_FAILURE;
    }

    char* cypher = caesar_cypher(str, key);
    printf("Cyphered text: %s\n", cypher);
    free(cypher); // Free allocated memory

    return EXIT_SUCCESS;
}
