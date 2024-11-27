#include <stdio.h>
//This code creates a Pascals Triangle based on how many levels the user wants

void Triangle_add(int levels_of_PT, int rows[][28]) {//This function creates the levels of the triangle
    for (int i = 0; i < levels_of_PT; ++i) {//The loop sets up each row to start and end with 1
        rows[i][0] = 1;
        rows[i][i] = 1;
        for (int t = 1; t < i; ++t) {//The loop does the math to find the inner elements in each row
            rows[i][t] = rows[i - 1][t -1] + rows[i - 1][t];

        }
    }
}

void Print_Triangle(int levels_of_PT, int rows[][28]) {//This function prints out each row in the triangle
    for (int i = 0; i < levels_of_PT; ++i) {//Lopp goes through each level
        for (int t = 0; t <= i; ++t) {//Prints out each number
            printf("%d ", rows[i][t]);
        }
        printf("\n");//Prints a new line when each row in the triangle is complete
    }
}

int main() {//My variables
    int levels_of_PT;
    int rows[28][28];//Arrays that hold a max of 28 elements
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");//User input
        scanf("%d", &levels_of_PT);

    Triangle_add(levels_of_PT, rows);//Calls the function to create the levels of the triangle
    Print_Triangle(levels_of_PT, rows);//Calls the function to print out each level in the triangle
}