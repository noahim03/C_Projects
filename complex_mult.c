// This code tells us how to multiple complex numbers
#include <stdio.h>
int main() {
//These are my variables
    int imaginary_num, real_num;
    int a, b, c, d;
//Asks the user for their complex numbers
    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d i + %d", &a, &b);
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d i + %d", &c, &d);
//This code shows how to use the FOIL method to multiple the complex numbers    
    imaginary_num = (b * c) + (a * d);
    real_num = (b * d) + ((-1 * (a * c)));
//This code gives an answer to the problem    
    printf("(%di + %d) * (%di + %d) = %di + %d\n", a, b, c, d, imaginary_num, real_num);

    return 0;
}