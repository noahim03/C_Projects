
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_helpers.h"

//Calcuulates  the full length of the string with all the words and the seperator word
int total_length(char** strings, int num_strings, char* seperator) {
    int total_length = 0;//Sets the length equal to 0

    for (int i = 0; i < num_strings; ++i) {//Loops through the string and adds the length of each word
        total_length += strlen(strings[i]);
    }
    total_length += (num_strings - 1) * strlen(seperator);//Adds the total length of the seperator word
    return total_length;
}
//Adds the seperator word inbetween all the words
void combine_with_seperator(char* result, char** strings, int num_strings, char* seperator) {
    result[0] = '\0';//Starts with an empty string

    for (int i = 0; i < num_strings; ++i) {//Loops through the strings and adds the current word to the result
        strcat(result, strings[i]);
        if (i < num_strings - 1) {//Add the seperator word, until it reaches the last word
          strcat(result, seperator);
        }
    }
}


char* join(char** strings, int num_strings, char* seperator){
    /*
      Create a new string by joining all of the strings in strings together
      with seperator between each string. If num_strings is <= 0
      returns the empty string. 
      

      @param strings: The strings to join together
      @param num_strings: The number of strings to join together
      @param seperator: The string to place between each string
      @returns: a new string with seperator between each string in strings
    */
    if (num_strings <=0) {//If there are no strings, it returns  an exmpty string
      return calloc(1, sizeof(char));//Allocates 1 byte to the empty string
    }
    int total_len = total_length(strings, num_strings, seperator);//Calculates the total length of the joined string and sets it equal to total_len
    char* result = malloc(total_len + 1);//Allocates memory for the reuslting string and add 1 for the null character
        if (result == NULL) {//Returns null if it fails
          return NULL;
        }
    combine_with_seperator(result, strings, num_strings, seperator);//Combines the strings with the seperator
    return result;
}

char* read_any_len_line() {
    /*
    Read a line of any length from the user input. 
    The newline character, while read, is not included in the returned string.
    @returns: The next line of characters from the input stream
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


