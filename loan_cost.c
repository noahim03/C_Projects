//This code shows how much your loan cost will be if you decide to take out a loan
#include <stdio.h>
#include <math.h>
int main() {
// These are variables for the code/Asks the user for their input
    double amount_borrowed;
    double annual_interest_rate;
    int num_of_months_to_pay;
    double monthly_payments;
    double monthly_interest_rate;
    double total_cost;
    double loan_cost;
    
    printf("Please enter the amount of money you borrowed: $");
    scanf("%lf", &amount_borrowed);
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &annual_interest_rate);
    printf("Please enter the number of payments to be made: ");
    scanf("%d", &num_of_months_to_pay);
// This code calculates the monthly interest rates and shows how much money you will pay per month
    monthly_interest_rate = annual_interest_rate / 12.00;
    monthly_payments = (amount_borrowed * monthly_interest_rate) / (1.00 - pow(1.00 + monthly_interest_rate, -num_of_months_to_pay));
//This code shows the total cost of the loan and much the interest on the loan you will have to pay
    total_cost = monthly_payments * num_of_months_to_pay;
    loan_cost = total_cost - amount_borrowed;
    printf("A loan of $%.2lf with an annual interest of %.2lf paid off over %d months will have monthly payments of $%.2lf.", amount_borrowed, annual_interest_rate, num_of_months_to_pay, monthly_payments);
    printf(" In total, you will pay $%.2lf, making the cost of your loan $%.2lf.", total_cost, loan_cost);


    
    
    
    
    
    
    
    
    
    
    
    return 0;

}