#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1024
#define LETTER_COUNT 26
#define COMMON_COUNT 10

char* caesar_decypher(char* cypher, int key) {
    int length = strlen(cypher);
    char* result = (char*)malloc(sizeof(char) * (length + 1));

    for (int i = 0; cypher[i] != '\0'; i++) {
        char c = cypher[i];
        if (isalpha(c)) { // Check if it's an alphabet character
            char base = islower(c) ? 'a' : 'A'; // Determine base for case
            result[i] = ((c - base - key + LETTER_COUNT) % LETTER_COUNT) + base;
        } else {
            result[i] = c; // Non-alphabetic character remains unchanged
        }
    }
    result[length] = '\0';

    return result;
}

char most_common_letter(char* cypher) {
    int counts[LETTER_COUNT] = {0}; // Initialize counts array with zeros

    for (int i = 0; cypher[i] != '\0'; i++) {
        char c = tolower(cypher[i]); // Convert to lowercase for uniformity
        if (isalpha(c)) {
            counts[c - 'a']++; // Increment count for the corresponding letter
        }
    }

    int max_index = 0;
    for (int i = 1; i < LETTER_COUNT; i++) {
        if (counts[i] > counts[max_index]) {
            max_index = i;
        }
    }

    return max_index + 'a';
}

char* read_cypher(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char* cypher = (char*)malloc(MAXN * sizeof(char));
    if (fgets(cypher, MAXN, file) == NULL) {
        perror("Error reading from file");
        fclose(file);
        free(cypher); // Free allocated memory before returning
        return NULL;
    }

    fclose(file);
    return cypher;
}

int main() {
    printf("Enter filename: ");
    char filename[MAXN];
    scanf("%s", filename);

    char* cypher = read_cypher(filename);
    if (cypher == NULL) {
        return EXIT_FAILURE;
    }

    char letters[COMMON_COUNT] = {'e', 't', 'a', 'o', 'i',
                                  'n', 's', 'r', 'h', 'l'};

    for (int i = 0; i < COMMON_COUNT; i++) {
        printf("The common letter is: %c\n", letters[i]);
        int key = most_common_letter(cypher) - letters[i];
        printf("The key is: %d\n", key);
        char* text = caesar_decypher(cypher, key);
        printf("Message: %s\n", text);
        printf("------------------------------------\n");
        free(text); // Free allocated memory for each decrypted text
    }

    free(cypher); // Free allocated memory for the cypher text
    return EXIT_SUCCESS;
}
