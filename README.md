# Coleman-Liau-Index-Calculator

This program calculates the **Coleman-Liau Index** (CLI) of a given text. The Coleman-Liau index is a readability test designed to gauge the understandability of English texts. It is used to estimate the grade level required to understand a text. The formula is based on the number of letters, words, and sentences in the text.

## Features

- **Calculate Text Statistics**: The program analyzes the number of letters, words, and sentences in the provided text.
- **Coleman-Liau Index Calculation**: Using the calculated text statistics, the program computes the Coleman-Liau index.
- **User Input Options**: You can input the text either directly or by uploading a `.txt` file.

## How It Works

The program performs the following steps:
1. **User Input**: The user is prompted to choose between entering the text manually or uploading a `.txt` file.
2. **Text Analysis**: The program counts the number of letters, words, and sentences.
3. **CLI Calculation**: The Coleman-Liau index is calculated using the formula: CLI = 0.0588 * L - 0.296 * S - 15.8

where:
- `L` is the average number of letters per 100 words,
- `S` is the average number of sentences per 100 words.
4. **Readability Rating**: The program outputs the readability level based on the Coleman-Liau index.

## Example Output
Text Statistics: Letters: 456 Words: 78 Sentences: 6 Coleman-Liau Index: 8.92

Readability: 9th grade level

## Usage

1. Clone this repository or download the source code.
2. Compile the program using a C compiler (e.g., GCC).
3. Run the executable and follow the instructions to either enter the text manually or upload a `.txt` file.
4. View the readability statistics and the Coleman-Liau index.

## How to Compile and Run

### To compile the program using GCC:
gcc coleman_liau.c -o coleman_liau
### To run the program:
./coleman_liau







