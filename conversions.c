//This program converts temperature measurements and distance measurements
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
//Tempurature Conversions
double FA_to_C(double F) {//Fahrenheit to Celsius
    return (F - 32.0) * (5.0 / 9.0);
}
double FA_to_K(double F) {//Fahrenheit to Kelvin
    return FA_to_C(F) + 273.15;
}
double C_to_FA(double C) {//Celsius to Fahrenheit
    return ((C * (9.0 / 5.0)) + 32);
}
double C_to_K(double C) {//Celsius to Kelvin
    return (C + 273.15);
}
double K_to_FA(double K) {//Kelvin to Fahrenheit
    return (((K - 273.15) * (9.0 / 5.0)) + 32);
}
double K_to_C(double K) {//Kelvin to Celsius
    return (K - 273.15);
}
//Distance Conversions
double I_to_F(double I) {//Inches to Feet
    return (I / 12.0);
}
double I_to_Y(double I) {//Inches to Yards
    return (I / 36.0);
}
double I_to_M(double I) {//Inches to Miles
    return (I / 63360.0);
}
double F_to_I(double F) {//Feet to Inches
    return (F * 12.0);
}
double F_to_Y(double F) {//Feet to Yards
    return (F / 3.0);
}
double F_to_M(double F){// Feet to MIles
    return (F / 5280.0);
}
double Y_to_I(double Y) {//Yards to Inches
    return (Y * 36.0);
}
double Y_to_F(double Y) {//Yards to Feet
    return (Y * 3.0);
}
double Y_to_M(double Y) {//Yards to Miles
    return (Y / 1760.0);
}
double M_to_I(double M) {//Miles to Inches
    return (M * 63360.0);
}
double M_to_F(double M) {//Miles to Feet
    return (M * 5280.0);
}
double M_to_Y(double M) {//Miles to Yards
    return (M * 1760);
}
//My variables 
int main() {
    char convert;//store the type of conversion (temp or dist)
    char old_temp, new_temp, old_dist, new_dist;//variabls that store the unit types
    double old_temp_num, new_temp_num, old_dist_num, new_dist_num;//variables that store the number values
    //User input
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    //This checks if scanf was able to read one character successfully.
    if (scanf(" %c", &convert) != 1) {
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    if (getchar() != '\n') {  //Checks if the character read is not a newline character ('\n'). A newline character means the user pressed the Enter key.
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    if (tolower(convert) != 't' && tolower(convert) != 'd') {//Checks if the input was the letter t or d
        printf("Unknown conversion type %c chosen. Ending program.\n", toupper(convert));
        exit(0);
    }
   //Swicth statment for temp or dist conversion
    switch (tolower(convert)) {
        case 't'://case for temp
            printf("Enter the temperature followed by its suffix (F, C, or K): ");
            if (scanf("%lf %c", &old_temp_num, &old_temp) != 2) {//This checks if scanf was able to read two characters successfully.
                printf("Invalid formatting. Ending program.\n");
                return 0;
            }
            else if (getchar() != '\n') { //Checks if there was an extra input
                 printf("Invalid formatting. Ending program.\n");
                    return 0;
            }
            if (tolower(old_temp) != 'f' && tolower(old_temp) != 'c' && tolower(old_temp) != 'k') {
                printf(" %c is not a valid temperature type. Ending program.", toupper(old_temp));//Checks if the input was the letter f, c, or k
                return 0;
            }
            printf("Enter the new unit type (F, C, or K): "); 
            if (scanf(" %c", &new_temp) != 1) {//This checks if scanf was able to read one character successfully.
                printf("Invalid formatting. Ending program");
                return 0;
            }
            else if (getchar() != '\n') { //Checks if there was an extra input
                printf("Invalid formatting. Ending program.\n");
                return 0;
            }
            if (tolower(new_temp) != 'f' && tolower(new_temp) != 'c' && tolower(new_temp) != 'k') {//Checks if the input was the letter f, c, or k
                printf(" %c is not a valid temperature type. Ending program.", toupper(new_temp));
                return 0;        
            }
            //changes the variable to lowercase letter
            old_temp = tolower(old_temp);
            new_temp = tolower(new_temp);
            //Temperature conversions
            if (new_temp == old_temp) {
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), old_temp_num, toupper(old_temp));
            }
            else if((new_temp == 'c') && (old_temp == 'f')) {
                new_temp_num = FA_to_C(old_temp_num);
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), new_temp_num, toupper(new_temp));
            }
            else if((new_temp == 'k') && (old_temp == 'f')) {
                new_temp_num = FA_to_K(old_temp_num);
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), new_temp_num, toupper(new_temp));
            }
            else if((new_temp == 'f') && (old_temp == 'c')) {
                new_temp_num = C_to_FA(old_temp_num);
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), new_temp_num, toupper(new_temp));
            }
            else if((new_temp == 'k') && (old_temp == 'c')) {
                new_temp_num = C_to_K(old_temp_num);
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), new_temp_num, toupper(new_temp));
            }
            else if ((new_temp == 'f') && (old_temp == 'k')) { 
                new_temp_num = K_to_FA(old_temp_num);
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), new_temp_num, toupper(new_temp));
            }
            else if ((new_temp == 'c') && (old_temp == 'k')) { 
                new_temp_num = K_to_C(old_temp_num);
                printf("%.2lf%c is %.2lf%c", old_temp_num, toupper(old_temp), new_temp_num, toupper(new_temp));
            }  
            break;

        case 'd': //case for distance
            printf("Enter the distance followed by its suffix (I,F,Y,M): "); //This checks if scanf was able to read two characters successfully.
            if (scanf("%lf %c", &old_dist_num, &old_dist) != 2) {
                printf("Invalid formatting. Ending program.\n");
                return 0;
            }
            else if (getchar() != '\n') { //Checks if there was an extra input
                 printf("Invalid formatting. Ending program.\n");
                    return 0;
            }
            if (tolower(old_dist) != 'i' && tolower(old_dist) != 'f' && tolower(old_dist) != 'y' && tolower(old_dist) != 'm') {////Checks if the input was the letter i, f, y, or m
                printf(" %c is not a valid distance type. Ending program.", toupper(old_dist));
                return 0;
            }
            printf("Enter the new unit type (I,F,Y,M): ");
            if (scanf(" %c", &new_dist) != 1) { //This checks if scanf was able to read one character successfully.
                printf("Invalid formatting. Ending program");
                return 0;
            }
            else if (getchar() != '\n') { //Checks if there was an extra input
                 printf("Invalid formatting. Ending program.\n");
                    return 0;
            }
            if (tolower(new_dist) != 'i' && tolower(new_dist) != 'f' && tolower(new_dist) != 'y' && tolower(new_dist) != 'm') {
                printf(" %c is not a valid distance type. Ending program.", toupper(new_dist)); //Checks if the input was the letter i, f, y, or m
                return 0; 
            } 
            //Changes the variable to lowercase
            old_dist = tolower(old_dist);
            new_dist = tolower(new_dist);
            //distance conversions
            if (new_dist == old_dist) {
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), old_dist_num, toupper(old_dist));
            }
            else if((new_dist == 'f') && (old_dist == 'i')) {
                new_dist_num = I_to_F(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'y') && (old_dist == 'i')) {
                new_dist_num = I_to_Y(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'm') && (old_dist == 'i')) {
                new_dist_num = I_to_M(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'i') && (old_dist == 'f')) {
                new_dist_num = F_to_I(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'y') && (old_dist == 'f')) {
                new_dist_num = F_to_Y(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'm') && (old_dist == 'f')) {
                new_dist_num = F_to_M(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'i') && (old_dist == 'y')) {
                new_dist_num = Y_to_I(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'f') && (old_dist == 'y')) {
                new_dist_num = Y_to_F(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'm') && (old_dist == 'y')) {
                new_dist_num = Y_to_M(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'i') && (old_dist == 'm')) {
                new_dist_num = M_to_I(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'f') && (old_dist == 'm')) {
                new_dist_num = M_to_F(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            else if((new_dist == 'y') && (old_dist == 'm')) {
                new_dist_num = M_to_Y(old_dist_num);
                printf("%.2lf%c is %.2lf%c", old_dist_num, toupper(old_dist), new_dist_num, toupper(new_dist));
            }
            break;
        }
    return 0;
        
    } 