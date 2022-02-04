#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getstr.h"


int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int argLen = strlen(argv[1]);

    if (argLen < 26) {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    char* key = argv[1];

    for (int i = 0; i < argLen; ++i) {
        if (!isalpha(key[i])) {
            printf("All characters must be alphabetic\n");
            return 1;
        }

        for (int j = i + 1; j < argLen; ++j) {
            if (key[i] == key[j]) {
                printf("Character must not repeat\n");
                return 1;
            }
        }
    }

    int len;
    char* text = get_string(&len);

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); ++i) {
        if (isupper(text[i])) {
            printf("%c", toupper(key[text[i] - 65]));
        } else if (islower(text[i])) {
            printf("%c", key[text[i]]);
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;

}