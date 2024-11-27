//This code finds whether or not a word is found inside another word
#include <stdio.h>
#include <string.h>

void remove_newline(char substring[]) {//This function removes the newline of a string
    int len_substring = strlen(substring);//Length of the substring
    
    if (len_substring > 0 && substring[len_substring - 1] == '\n') {//If the string's length is greater than 0 and the last character in the string is a newline, 
        substring[len_substring - 1] = '\0';                        //it will replace the newline with the null character
    }
}

int find(char substring[], char string[]) {//This function finds the position of the substring in the string
    remove_newline(substring);//Calls the function to remove the newline in substring
    int len_substring = strlen(substring);//Length of the substring

    if (len_substring == 0) {//If the length of the substring is 0, returns 0
        return 0;
    }

    char *position = strstr(string, substring);//Finds where the substring first occurs in string, position points to where substring starts in string
        if (position) {//If the substring is found
            int index = position - string;//Calcualates the index of where the first occurence of substring in string
            return index;
    }
    
    return -1;//Returns -1 if the substring is not found in string
}

int main() {
    char string[100], substring[100];//My arrays, holding a max of 100 characters
    
    printf("Enter the string to search: ");//User input
        fgets(string, sizeof(string), stdin);//Reads the input of string
    
    printf("Enter the substring to search for: ");//User input
        fgets(substring, sizeof(substring), stdin);//Reads the input of substring

    int index = find(substring, string);//Calls the find function and stores it into index
    if (index >= 0) {//If the index is greater than or equal to 0, they found the substring
        printf("\"%s\" first appears at index %d in \"%s\".", substring, index, string);
    } else {//If the index is less than 0, then they did not find a substring
        printf("\"%s\" does not appear in \"%s\".", substring, string);
    }
    return 0;
}