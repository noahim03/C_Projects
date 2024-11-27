//The code will show you how much money you will recieve split into hundreds, fiftys, tens, fives, ones.
#include <stdio.h>
int main() {
    //My variables/Asks user for how much money they want to take out
    int amount_withdrew, hundred, fifty, twenty, ten, five, one;
    
    printf("Please enter the amount of money you wish to withdraw:"); 
    scanf("%d", &amount_withdrew);
    
    // This varibale will caculate how many hundreds you will recieve
    hundred = amount_withdrew / 100;
    printf("You received %d hundred(s)\n", hundred);

    // This varibale will caculate how many fiftys you will recieve
    fifty = (amount_withdrew - (hundred * 100)) / 50;
    printf("You received %d fifty(s)\n", fifty);

    // This varibale will caculate how many twenties you will recieve
    twenty = (amount_withdrew - (hundred * 100) - (fifty * 50)) / 20;
    printf("You received %d twenty(s)\n", twenty);

    // This varibale will caculate how many tens you will recieve
    ten = (amount_withdrew - (hundred * 100) - (fifty * 50) - (twenty * 20)) / 10;
    printf("You received %d ten(s)\n", ten);

    // This varibale will caculate how many fives you will recieve
    five = (amount_withdrew - (hundred * 100) - (fifty * 50) - (twenty * 20) - (ten * 10)) / 5;
    printf("You received %d five(s)\n", five);

    // This varibale will caculate how many ones you will recieve
    one = (amount_withdrew - (hundred * 100) - (fifty * 50) - (twenty * 20) - (ten * 10) - (five * 5)) / 1;
    printf("You received %d one(s)\n", one);



    return 0;
}