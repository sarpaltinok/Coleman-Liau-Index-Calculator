#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void calculate_text_stats(const char *text, int *letters, int *words, int *sentences);
float calculate_coleman_liau_index(int letters, int words, int sentences);

int main() {
    char choice;
    char text[1000];   // Buffer to hold the text
    int letters, words, sentences;

    // Ask user for input method
    printf("How would you like to enter the text?\n");
    printf("1. Enter the text directly\n");
    printf("2. Upload a TXT file\n");
    printf("Make your choice (1 or 2): ");
    scanf(" %c", &choice);
    getchar(); // Clear the newline character

    if (choice == '1') {
        // Get text from user input
        printf("Please enter the text: ");
        fgets(text, sizeof(text), stdin);
    } else if (choice == '2') {
        // Get file name from user
        char filename[100];
        printf("Please enter the name of the TXT file (e.g., text.txt): ");
        scanf("%s", filename);

        // Open the file
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("The file could not be opened. Please check the file name.\n");
            return 1; // Exit on error
        }

        // Read text from the file
        printf("\nReading the file...\n");
        fgets(text, sizeof(text), file);
        fclose(file); // Close the file
    } else {
        printf("Invalid selection! Exiting the program.\n");
        return 1;
    }

    // Calculate text statistics
    calculate_text_stats(text, &letters, &words, &sentences);

    // Calculate the Coleman-Liau index
    float index = calculate_coleman_liau_index(letters, words, sentences);

    // Print the result
    printf("\nText Statistics:\n");
    printf("Number of Letters: %d\n", letters);
    printf("Number of Words: %d\n", words);
    printf("Number of Sentences: %d\n", sentences);
    printf("Coleman-Liau Index: %.2f\n", index);

    // Readability level
    if (index < 1) {
        printf("Readability: 1st grade and below\n");
    } else if (index > 16) {
        printf("Readability: College level\n");
    } else {
        printf("Readability: %.0fth grade level\n", index);
    }

    return 0;
}

// Function to calculate the number of letters, words, and sentences in the text
void calculate_text_stats(const char *text, int *letters, int *words, int *sentences) {
    *letters = 0;
    *words = 1;  // Count the first word
    *sentences = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            (*letters)++;  // Increment letter count
        } else if (isspace(text[i])) {
            (*words)++;    // Space indicates a new word
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            (*sentences)++;  // Period, exclamation mark, or question mark indicates the end of a sentence
        }
    }
}

// Function to apply the Coleman-Liau formula
float calculate_coleman_liau_index(int letters, int words, int sentences) {
    float L = (letters / (float)words) * 100;    // Number of letters per 100 words
    float S = (sentences / (float)words) * 100; // Number of sentences per 100 words
    return 0.0588 * L - 0.296 * S - 15.8;
}
