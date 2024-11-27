//This code finds the value of foo(n) using a recursive call
#include <stdio.h>
#include <stdlib.h>

//This function calculates the value of foo(n)
int foo_calc(int n, int* checker) {
    int arr[] = {3, 6, 2, 7};//Stores the values of foo0, foo1, foo2, foo3
    //Base case
    if (n < 0) {//If the number is less than 0, return 0
        return 0;
    }
    else if (checker[n] != -1) {//Checks if the value at foo(n) already was calculated
        return checker[n];
    }
    else if (n <= 3 && n >= 0) {//If n is inbetween 0 and 3 inclusive, then it returns the set value at foo(n)
        return checker[n] = arr[n];
    }
    else {
    checker[n] = foo_calc(n - 1, checker) + foo_calc(n - 2, checker) + foo_calc(n - 3, checker) - foo_calc(n - 4, checker) + 1;//Recursive call, calculates foo(n) 
    }
    return checker[n];//Returns the value of foo(n)
}

int main() {
    int n, result;//My variables

    printf("Enter a value for n: ");//Ask the user for input
        scanf("%d", &n);//Store the input

    int* checker = (int*)malloc((n + 1) *sizeof(int));//Allocates memory for the checker array
    for (int i = 0; i <= n; ++i) {//Sets all the elements eqaul to -1
        checker[i] = -1;
    }
    
    result = foo_calc(n, checker);//Call the function and set the number eqaul to the result 
    printf("Foo(%d) = %d", n, result);//Print the number
    
    free(checker);
    return 0;
}