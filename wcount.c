#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/*
This program counts the number of words in a file

1. Get file input
2. Count the # of words
3. Show # of words in file
*/
int count_words(FILE* word_file, int word_counter) {
/* 
This counts the words that are in the file
@param word_file: the word file being read in
@param word_counter: The counter for the number of words
@returns total word count
*/
    char character;
    bool whitespace = true;

    // We start at the beginning of the file
    fseek(word_file, 0, SEEK_SET);

    // Count the words
    while (feof(word_file) == 0) {
        fscanf(word_file, "%c", &character); // Read the character

        if (whitespace && !isspace(character)) { // When in word
            ++word_counter; 
            whitespace = false;
        } else if (!whitespace && isspace(character)) { // When in whitespace
            whitespace = true; 
        }
    }

    // Checks if file is empty
    int fileSize = ftell(word_file);

    if (fileSize == 0) {
        word_counter = 0;
    }

    return word_counter;
}

int main(int argc, char* argv[]) {
/*
Organizes the program and opens the file
1. Open the file
2. Count the word
3. Close the file
4. Show number of words
@param argc: Number of arguments and gets command
@param argv[]: Gets the argument for the file
@return 0 for completion
*/
    int word_counter = 0;

    // Open teh file
    FILE* word_file = fopen(argv[1], "r");

    // Count words then close file
    word_counter = count_words(word_file, word_counter);
    fclose(word_file);

    // Show user the number of words
    printf("There are %d word(s).\n", word_counter);

    return 0;
}