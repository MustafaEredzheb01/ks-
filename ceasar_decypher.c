#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

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
            result[i] = ((c - 'A' - key + 26) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            result[i] = ((c - 'a' - key + 26) % 26) + 'a';
        } else {
            result[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    result[length] = '\0';

    return result;
}

int main() {
    char cypher[MAXN];
    printf("Enter cypher text: ");
    if (scanf("%s", cypher) != 1) {
        printf("Error reading cypher text\n");
        return EXIT_FAILURE;
    }

    int key;
    printf("Enter key: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid key\n");
        return EXIT_FAILURE;
    }

    char* result = caesar_decipher(cypher, key);
    printf("Deciphered text: %s\n", result);
    free(result); // Free allocated memory

    return EXIT_SUCCESS;
}
