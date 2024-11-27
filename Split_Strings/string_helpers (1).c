
#include "string_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Calculates the full length of the string with all the words
int total_length(char* string) {
    int total_length = strlen(string);
    
    return total_length;
}
//Counts the times the delimiter appears in the string
int count_delimiter(char* string, const char* const delimiter) {
    int count = 0;//Set eqaul to 0
    int delimiter_len = strlen(delimiter);//Length of the delimiter
    char* occurences = strstr(string, delimiter);//Finds the first occurence of the delimiter
    
    while(occurences != NULL) {//Loops until the delimiter is no longer found
        ++count;//Adds to the count
        occurences = strstr(occurences + delimiter_len, delimiter);//Finds the next occurence of the delimiter in the string
    }
    return count;
}
//Creates a new string by copying a piece of the original string
char* substring(char* start, char* end) {
    int length = end - start;//Length of the part to copy
    char* result = malloc((length + 1) * sizeof(char));//Allocates memory for the new string
    
    strncpy(result, start, length);//Copies part of the string into the new string
    result[length] = '\0';//Adds the null terminator to the end 
    
    return result;
}

void split(char* string, const char* const delimiter,
           char*** splits, int *len){
    /*
      Split string on delimiter into an array of strings.
      @param string: the string to split
      @param delimiter: the delimiter to split on
      @output_param splits: The output array to store the strings 
      into. Assume the value at *splits is uninitialized.   
      @output_param len: The number of strings in splits.
        Assume the value at *len is uninitialized.
    */
    int delimiter_count = count_delimiter(string, delimiter);
    *len = delimiter_count + 1;
    *splits = malloc(*len * sizeof(char*));
    
    int index = 0;
    char* start = string;
    char* end = strstr(string, delimiter);
    int delimiter_len = strlen(delimiter);

    while (end != NULL) {
        (*splits)[index++] = substring(start, end);
        start = end + delimiter_len;
        end = strstr(start, delimiter);
    }
    (*splits)[index] = malloc((strlen(start) + 1) * sizeof(char));
    strcpy((*splits)[index], start);
}

char* read_any_len_line() {
    /*
    Read a line of any length from the user input. 
    @returns: The next line of characters from the input stream.
    The newline character, while read, is not included in the returned string.
    @modifies: stdin
    */
    char* strings = (char*)malloc(sizeof(char));                      
    if (strings == NULL) {
        return NULL;                     
    }

    int str_length = 0;
    int character;  

    while ((character = getchar()) != '\n') {     
        char* new_strings = realloc(strings, (str_length + 1) * sizeof(char) + 1);  
        if (new_strings == NULL) {
            free(strings);
            return NULL;
        }
        strings = new_strings;
        strings[str_length] = character;  
        ++str_length;             
    }
    strings[str_length] = '\0';              
    return strings;
}




