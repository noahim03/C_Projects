#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*
This program helps find us the determinant of a matrix

1. We read the file
2. We assign the matrix
3. We start recursively finding the determinant
4. We clear the matrix
*/
int main(int argc, char** argv) {
/*
This function opens the file and organizes the functions
@param argc: is for the command
@param argv: is for the text file
@returns 0 for completion
*/
    double determinant;

    // Open the file
    FILE* fp = fopen(argv[1], "r");

    struct Matrix mat = matrixSetUp(fp); // Set up the matrix

    // Find the determinant
    determinant = findDeterminant(mat.matrix, mat.rows, mat.cols);
    printf("The determinant is %.2lf.\n", determinant);

    deleteMatrix(mat); // Free memory
    fclose(fp); // Close file

    return 0;
}
