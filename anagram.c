
//This code is used to determine whether or not 2 words are anagrams
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//This function turns the first string into lowercase letters
void to_lowercase1(char first_word[], char lowercase_word1[]) {
    for (int i = 0; i < (int)strlen(first_word); ++i) {
        lowercase_word1[i] = tolower(first_word[i]);
    }
    lowercase_word1[strlen(first_word)] = '\0';
}
//This function turns the second string into lowercase letters
void to_lowercase2(char second_word[], char lowercase_word2[]) {
    for (int i = 0; i < (int)strlen(second_word); ++i) {
        lowercase_word2[i] = tolower(second_word[i]);
    }
    lowercase_word2[strlen(second_word)] = '\0';
}

//This function finds the string length of the first word
int str_len1(char first_word[]) {
    int i = 0;
    while(first_word[i] != '\0') {
        ++i;
    }
    return i;
}
//This function finds the string length of the second word
int str_len2(char second_word[]) {
    int i = 0;
    while(second_word[i] != '\0') {
        ++i;
    }
    return i;
}
//This function puts the first word in alphabetical order. Th function compares each pair of adjacent characters. 
//If the first character is greater than the second character, they switch.
void sort_str1(char first_word[], char word1[], char lowercase_word1[]) {
    to_lowercase1(first_word, lowercase_word1);
    strcpy(word1, lowercase_word1);
    
    for (int i = 0; i < (int)strlen(word1) - 1; ++i) {
        for (int j = 0; j < (int)strlen(word1) - i - 1; ++j) {
            if (word1[j] > word1[j + 1]) {
                char temp_word = word1[j];
                word1[j] = word1[j + 1];
                word1[j + 1] = temp_word;
            }
        }
    }
}
//This function puts the second word in alphabetical order. Th function compares each pair of adjacent characters. 
//If the first character is greater than the second character, they switch.
void sort_str2(char second_word[], char word2[], char lowercase_word2[]) {
    to_lowercase2(second_word, lowercase_word2);
    strcpy(word2, lowercase_word2);

    for (int i = 0; i < (int)strlen(word2) - 1; ++i) {
        for (int j = 0; j < (int)strlen(word2) - i - 1; ++j) {
            if (word2[j] > word2[j + 1]) {
                char temp_word = word2[j];
                word2[j] = word2[j + 1];
                word2[j + 1] = temp_word;
            }
        }
    }
}
//This function prints whether or not the words are anagrams
void PrintAnagram(char first_word[], char second_word[]) {
    char word1[28], word2[28];
    char lowercase_word1[28], lowercase_word2[28];
    sort_str1(first_word, word1, lowercase_word1);
    sort_str2(second_word, word2, lowercase_word2);
    //This compares the alphabetical order of the strings, the ASCII values of the string, and the string lengths
    if (str_len1(first_word) == str_len2(second_word) && strcmp(word1, word2) == 0) {
        printf("%s is an anagram of %s", first_word, second_word);
    }
    else {
    printf("%s is NOT an anagram of %s", first_word, second_word);
    }

}

int main() {//My arrays, max of 28
    char first_word[28], second_word[28];
    
    printf("Please enter the first word: ");//User input of first word
        scanf("%s", first_word);

    printf("Please enter the second word: ");//User input of second word
        scanf("%s", second_word);

    PrintAnagram(first_word, second_word);//Calls the function to print whether or not the words are anagrams
    
    return 0;
}