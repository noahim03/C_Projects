//This programs takes a binary string, and replaces all the x characters to 0 and 1, creating all possible combinations
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void binary(char* string,int index) {
    //Base case: if the end of the string is reached, print out the value
    if(string[index] == '\0') {
        printf("%s\n", string);
        return;
    }
    if(toupper(string[index]) == 'X') {//If the character is X change it to 0 or 1
        string[index] = '0';//Replace x with 0 and move onto the next character
        binary(string, index + 1);

        string[index] = '1';//Replace x with 1 and move onto the next character
        binary(string, index + 1);

        string[index] = 'X';//Used to backtrack after recursion of both cases
    }
    else {
        binary(string, index + 1);//If the character is no x, move onto the next character
    }
}

int valid_input(char* string) {//Validates if the string contians only 0, 1, and x
    for(int i = 0; string[i] != '\0'; ++i) {
        if(string[i] != '0' && string[i] != '1' && toupper(string[i]) != 'X') {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {//Checks if there is only 1 argument
        return 1;
    }
    char *binary_str = argv[1];//Gets the inputed string from the command line
    char *string = (char*)malloc((strlen(binary_str) + 1) * sizeof(char));//Allocates memory for the inputed string
    strcpy(string, binary_str);//Copies the inputed string into the allocated space

    if(!valid_input(string)) {//Calls the valid function to check whether the string only contains the said characters
        return 1;
    }
    binary(string, 0);//Calls the function to generate all the combinations

    free(string);//Frees the allocated memory
    return 0;
}