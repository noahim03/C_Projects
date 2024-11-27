//This code finds the solution(s) using the quadradic formula
#include <stdio.h>
//Imports the square root, power, absolute value
#include <math.h> 
//Function for the b^2 part of the formula
double squared(double b) {
    return b * b;
}
//Function for the squareroot of the discriminant 
double sqrtroot(double a, double b, double c) {
    return sqrt(squared(b) - (4 * a * c));
}
//Variables for the code/Asks for the users input
int main() {
    double a, b, c;
    double discriminant;
    double solution_1;
    double solution_2;
    double solution_3;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
//Finds the solutions of the quadratic formula
    solution_1 = ((-1.00 * b) + sqrtroot(a, b, c)) / (2 * a);
    solution_2 = ((-1.00 * b) - sqrtroot(a, b, c)) / (2 * a);

//Finds the discriminant    
    discriminant = squared(b) - (4 * a * c);
//If the disiminant is positive, then you should have 2 answers, if it is equal to 0 then you should have 1 answer, 
//and if it a negative number then theer are no real solutions     
    if (discriminant > 0) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution_1);
        printf("Solution 2: %.2lf", solution_2);
    }
    else if (discriminant == 0) {
        solution_3 = (-1.00 * b) / (2 * a);
            printf(" There is one real solution: %.2lf", solution_3);
        }   
    else {
        printf(" There are no real solutions");
    }
    return 0;
}
