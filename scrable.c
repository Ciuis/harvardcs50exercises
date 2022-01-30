#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getstr.h"

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);

int main(void) {
    // Get input words from both players
    char* word1;
    char* word2;
    int len;
    printf("Player 1: ");
    word1 = get_string(&len);
    printf("Player 2: ");
    word2 = get_string(&len);


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%s", score1 > score2 ? "Player 1 wins\n" : "Player 2 wins");

    return 0;
}

int compute_score(char* word) {
    for (int i = 0; i < strlen(word); ++i) {
        if ((char)isupper(word[i])) {
            word[i] = (char)tolower(word[i]);
        }
    }

    int score = 0;
    for (int i = 0; i < strlen(word); ++i) {
        int n = 0;

        // I'm sure it's not meet expectations but why not
        switch(word[i]) {
            case 'a': case 'e': case 'i': case 'l': case 'n': case 'o': case 'r': case 's': case 't': case 'u':
                n = 1;
                break;
            case 'd': case 'g':
                n = 2;
                break;
            case 'b': case 'c': case 'm': case 'p':
                n = 3;
                break;
            case 'f': case 'h': case 'v': case 'w': case 'y':
                n = 4;
                break;
            case 'k':
                n = 5;
                break;
            case 'j': case 'x':
                n = 8;
                break;
            case 'q': case 'z':
                n = 10;
                break;
        }
        score += n;
    }

    return score;
}