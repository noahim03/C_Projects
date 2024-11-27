#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "read_lines.h"


void read_lines(FILE* fp, char*** lines, int* num_lines) {
  /*
      read all of the lines in fp into lines and set num_lines to be the total number of lines in the file.
      @fp: a file pointer opened in read mode
      @lines: a pointer indicating where the lines should be placed. If there are no lines in a fill, lines
              will be set to NULL
      @num_lines: a pointer to the number of lines. set to the number of lines contained within lines
      @modifies: lines, num_lines
  */
    char character;
    *num_lines = 0;

    // Count the number of lines in the file
    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp, "%c", &character) == 1) {
        if (character == '\n') {
            (*num_lines)++;
        }
    }

    // Check if the last line doesn't end with a newline
    fseek(fp, -1, SEEK_END);
    fscanf(fp, "%c", &character);
    if (character != '\n') {
        (*num_lines)++;
    }

    // If no lines are found, set lines to NULL
    if (*num_lines == 0) {
        *lines = NULL;
        return;
    }

    // Allocate memory for lines
    *lines = malloc(*num_lines * sizeof(char*));
    if (*lines == NULL) {
        exit(1);
    }

    // Reset file pointer to start reading lines
    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < *num_lines; i++) {
        int size_line = 0;
        int pos_start = ftell(fp); // Mark the start of the line

        // Determine the length of the line
        while (fscanf(fp, "%c", &character) == 1 && character != '\n') {
            size_line++;
        }

        // Allocate memory for the line, including null terminator
        (*lines)[i] = malloc((size_line + 1) * sizeof(char));
        if ((*lines)[i] == NULL) {
            exit(1);
        }

        // Read the line into memory
        fseek(fp, pos_start, SEEK_SET);
        for (int j = 0; j < size_line; j++) {
            fscanf(fp, "%c", &((*lines)[i][j]));
        }
        (*lines)[i][size_line] = '\0'; // Null-terminate the string

        // Skip the newline character, if present
        if (character == '\n') {
            fseek(fp, 1, SEEK_CUR);
        }
    }

    // Check if the file is empty
    int fileSize = ftell(fp);
    if (fileSize == 0) {
      lines = NULL;
      *num_lines = 0;
    }

}