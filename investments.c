#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
Advise on if user should focus on investments or paying off loans based on retirement age
Validate all input and keep asking for new input if previous input is invalid
*/


bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
/*
 See if the input matches with the format of the question
 @numArgsRead is the number of arguments read by the scanf function
 @numArgsNeeded is the number of arguments that are needed to satisfy the scanf function
 @returns whether or not the input matches the format
 */
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); //45  bob  \n
if(!isspace(character)){ //found a non whitespace character on the way to the end of the line
formatIsGood = false;
}
}while(character != '\n'); //read characters until the end of the line
  return formatIsGood;
}

double getValidDouble(const char* prompt){
/*
 See if a double input has the right format (right number of arguments)
 @prompt is the question output right before reading the double
 @returns the valid double 
 */
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num); //waffles\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

double getDoubleAtLeast(double min_val, const char* prompt){
/*
 See if a double is greater than a certain value
 @min_val is the value that the double should be greater than
 @prompt is the prompt output right before reading the double
 @returns the valid double
 */
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}


double getReturnInvestmentPriority(double debt, double min_payment, double monthly_interest, double monthly_ROR, double current_age, double retirement_age, double retirement_savings_monthly) {
    /*
    See how much money you would have if you prioritize investments
    debt is amount of debt
    @min_payment is minimum monthly loan payment
    @monthly_ROR is monthly return on investment
    @current_age is current age
    @retirement_age is the age you want to retire at
    @retirement_savings_monthly is the amount of money you want to put towards retirement each month
    @returns the amount of money you will have by retirement if you prioritize investing
    */
    int months_left = retirement_age - current_age;
    double investments = 0;
    for (int m = 0; m < months_left; ++m){
        double debt_interest = debt * monthly_interest;
        double investment_interest = investments * monthly_ROR;
        debt = debt + debt_interest;
        investments = investments + investment_interest;

        if (debt < min_payment) {
            investments = investments + retirement_savings_monthly - debt;
            debt = 0;
        } else {
            debt = debt - min_payment;
            investments = investments + retirement_savings_monthly - min_payment;
        }
    }
    return investments - debt;

}

double getReturnLoanPriority(double debt, double monthly_interest, double monthly_ROR, double current_age, double retirement_age, double retirement_savings_monthly) {
    /*
    See how much money you would have if you prioritize paying off loan
    @debt is amount of debt
    @min_payment is minimum monthly loan payment
    @monthly_ROR is monthly return on investment
    @current_age is current age
    @retirement_age is the age you want to retire at
    @retirement_savings_monthly is the amount of money you want to put towards retirement each month
    @returns the amount of money you will have by retirement if you prioritize paying off your loan
    */
   int months_left = retirement_age - current_age;
   double investments = 0;
   for (int m = 0; m < months_left; ++m) {
    double debt_interest;
    double investment_interest;
    debt_interest = debt * monthly_interest;
    debt = debt + debt_interest;
    investment_interest = investments * monthly_ROR;
    investments = investments + investment_interest;
   
    if (debt > retirement_savings_monthly) {
        debt = debt - retirement_savings_monthly;
    }
    else if (debt < retirement_savings_monthly) {
        investments = investments + retirement_savings_monthly - debt;
        debt = 0;
    }
   }
    return investments - debt;
}



int main() {
    double debt = getDoubleAtLeast(0,"Enter how much you owe in loans: ");
    double monthly_interest = getDoubleAtLeast(0, "Enter the annual interest rate of the loans: ");
    double min_payment = getDoubleAtLeast(0, "Enter your minimum monthly loan payment: ");
    double retirement_savings_monthly = getDoubleAtLeast(min_payment, "Enter how much money you will be putting towards loans/retirement each month: ");
    double current_age = getDoubleAtLeast(0, "Enter your current age: ");
    double retirement_age = getDoubleAtLeast(current_age, "Enter the age you plan to retire at: ");
    double monthly_ROR = getDoubleAtLeast(0, "Enter your predicted annual rate of return: ");

    double return_from_investment_priority = getReturnInvestmentPriority(debt, min_payment, monthly_interest / 12.0, monthly_ROR / 12.0, current_age * 12.0, retirement_age * 12.0, retirement_savings_monthly);
    double return_from_loan_priority = getReturnLoanPriority(debt, monthly_interest / 12.0, monthly_ROR / 12.0, current_age * 12.0, retirement_age * 12.0, retirement_savings_monthly);

    if (return_from_investment_priority >= return_from_loan_priority) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.\n", return_from_investment_priority, return_from_loan_priority);
    } else {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", retirement_savings_monthly);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", return_from_loan_priority, return_from_investment_priority);
    }

    return 0;
}
