// This code will show what grade you need on the final to get an A in the class

#include <stdio.h>
int main() {
 // This code gets a letter grade from the user   
    char letter_grade;
    printf("Enter the grade you want in the class: ");
    scanf("%c", &letter_grade);
// This code gets the percent needed to get that letter grade from the user
    double percent_needed_to_get_grade;
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &percent_needed_to_get_grade);
// This code gets the current percent the user has in the class
    double current_percent;
    printf("Enter your current percent in the class: ");
    scanf("%lf", &current_percent);
// This code gets the weight of the final in the class
    double weight_of_final;
    printf("Enter the weight of the final: ");
    scanf("%lf", &weight_of_final);

    double final_grade_needed;
// This code gets the grade you need to get on the final to get your desired grade in the class
    final_grade_needed = (percent_needed_to_get_grade - (1.00 - (weight_of_final / 100.00)) * current_percent) / (weight_of_final / 100.00);
    printf("You need to get at least %.2f%% on the final to get a %c in the class.\n", final_grade_needed, letter_grade);

    return 0;
}