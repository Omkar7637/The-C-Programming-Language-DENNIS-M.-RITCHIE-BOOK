#include <stdio.h>

#define MAX_WORD_LENGTH 20   // Max word length to track
#define MAX_HEIGHT 15        // Max height for the histogram

int main() {
    int c, word_len = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};  // Array to store word lengths (up to MAX_WORD_LENGTH)
    int max_count = 0;  // Max count of words for a particular length

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_len > 0) {
                if (word_len <= MAX_WORD_LENGTH) {
                    ++word_lengths[word_len];
                    if (word_lengths[word_len] > max_count) {
                        max_count = word_lengths[word_len];  // Track the maximum count
                    }
                }
                word_len = 0;
            }
        } else {
            ++word_len;
        }
    }

    // Handle the last word
    if (word_len > 0 && word_len <= MAX_WORD_LENGTH) {
        ++word_lengths[word_len];
        if (word_lengths[word_len] > max_count) {
            max_count = word_lengths[word_len];
        }
    }

    // Print vertical histogram
    printf("\nVertical Histogram of Word Lengths:\n");

    for (int i = MAX_HEIGHT; i > 0; --i) {
        for (int j = 1; j <= MAX_WORD_LENGTH; ++j) {
            if (word_lengths[j] >= i * max_count / MAX_HEIGHT) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print word lengths at the bottom
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("---");
    }
    printf("\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("%2d ", i);
    }
    printf("\n");

    return 0;
}
