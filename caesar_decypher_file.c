#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#define MAXN 1000

char* caesar_decypher(char* cypher, int key) {
    int length = strlen(cypher);
    char* result = (char*)malloc(sizeof(char) * (length + 1));

    int i = 0;
    while (cypher[i] != '\0') {
        char c = cypher[i];
        if (isupper(c)) // Check if the character is uppercase
            result[i] = ((c - 'A' - key + 26) % 26) + 'A';
        else if (islower(c)) // Check if the character is lowercase
            result[i] = ((c - 'a' - key + 26) % 26) + 'a';
        else // For non-alphabetic characters
            result[i] = c;
        i++;
    }
    result[i] = '\0';

    return result;
}

char* read_cypher(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file"); // Use perror for error reporting
        return NULL;
    }

    char* cypher = (char*)malloc(MAXN * sizeof(char));
    if (fgets(cypher, MAXN, file) == NULL) {
        perror("Error reading from file");
        fclose(file); // Close the file before returning
        free(cypher); // Free allocated memory
        return NULL;
    }

    fclose(file);
    return cypher;
}

int main() {
    char filename[MAXN];
    printf("Enter filename: ");
    if (scanf("%s", filename) != 1) {
        printf("Error reading filename\n");
        return EXIT_FAILURE;
    }

    char* cypher = read_cypher(filename);
    if (cypher == NULL) {
        return EXIT_FAILURE;
    }

    int key;
    printf("Enter key: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid key\n");
        free(cypher);
        return EXIT_FAILURE;
    }

    char* result = caesar_decypher(cypher, key);
    printf("%s\n", result);

    // Free allocated memory
    free(cypher);
    free(result);

    return EXIT_SUCCESS;
}
