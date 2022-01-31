#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getstr.h"
#include <math.h>

int countLetters(char* text);
int countWords(char* text);
int countSentences(char* text);

int main (void) {
    int* len;
    char* text;

    text = get_string(&len);

    int W = countWords(text);
    int letters = countLetters(text);
    int sentences = countSentences(text);
    double L = ((float)letters / W) * 100;
    double S = ((float)sentences / W) * 100;

    printf("Letters: %d\nWords: %d\nSentences: %d\nL = %f\nS = %f\n", letters, W, sentences, L, S);

    double index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    if ((int)index < 1) {
        printf("Before grade 1\n");
    } else {
        printf("Grade %d\n", (int)index);
    }


}

int countLetters(char* text) {
    int lCount = 0;

    for (int i = 0; i < strlen(text); ++i) {
        if (isalpha(text[i])) {
            lCount++;
        }
    }
    return lCount;
}

int countWords(char* text) {
    int wCount = 0;

    for (int i = 0; i < strlen(text); ++i) {
        if (text[i] == ' ') {
            wCount++;
        }
    }

    return wCount + 1;
}

int countSentences(char* text) {
    int sCount = 0;

    for (int i = 0; i < strlen(text); ++i) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sCount++;
        }
    }

    return sCount;
}
