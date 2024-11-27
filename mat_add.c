#include <stdio.h> //This code adds two Matrixs together

void input_for_MatrixA(int numRows, int numCols, int Matrix_A[]) { //This function uses a for loop to get the user input and stores the values into Matrix A
    printf("Enter Matrix A\n");
    for (int i = 0; i < numRows * numCols; ++i) {
        scanf("%d", &Matrix_A[i]);
    }
}

void input_for_MatrixB(int numRows, int numCols, int Matrix_B[]) {//This function uses a for loop to get the user input and stores the values into Matrix B
    printf("Enter Matrix B\n");
    for (int i = 0; i < numCols * numRows; ++i) {
        scanf("%d", &Matrix_B[i]);
    }
}

void add_Matrix(int Matrix_A[], int Matrix_B[], int result[], int numRows, int numCols) {// This functions adds Matrix A and B together and stores the value into result
    for (int i = 0; i < numRows * numCols; ++i) {
        result[i] = Matrix_A[i] + Matrix_B[i];
    }
}

void printMatrix(int numRows, int numCols, int result[]) {//This function prints out all the elements in result into a table format
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            printf("%d ", result[row * numCols + col]);
        }
        printf("\n");
    }
}


int main() {//My variables
    int numRows, numCols;
    int Matrix_A[100000], Matrix_B[100000], result[100000];//Arrays that store the Matrix values

    printf("Please enter the number of rows: ");//User input
    scanf("%d", &numRows);

    printf("Please enter the number of columns: ");//User input
    scanf("%d", &numCols);

    input_for_MatrixA(numRows, numCols, Matrix_A);//Calls the function to input values for Matrix A
    input_for_MatrixB(numCols, numRows, Matrix_B);//Calls the function to input valuues for Matrix B
    add_Matrix(Matrix_A, Matrix_B, result, numRows, numCols);//Calls the function to add the Matrix together

    printf("A + B =\n");
    printMatrix(numRows, numCols, result);//Calls the function to print the results
  
  return 0;
}