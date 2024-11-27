#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

double findDeterminant(double** matrix, int row, int col) {
/*
This function recursively finds the determinant for us
@param matrix: is the matrix that is recursively shrunken to find the determinant
@param row: are the number of rows that are in the matrix
@param col: are the number of columns that are in the matrix
@returns the total determinant calculation value
*/
    double determinant = 0.0; // Total

    // Base Case if 2 x 2
    if ((row == 2) && (col == 2)) { // If 2x2, then return
        double a = matrix[0][0]; // top left
        double b = matrix[0][1]; //top right
        double c = matrix[1][0]; // bottom left
        double d = matrix[1][1]; //bottom right
        return (a*d) - (b*c);    
    } else if ((row >= 3) && (col >= 3)) { // If it is not our base case
        
        for (int i = 0; i < col; i++) { // Make our determinant mutiplier row

            // Our temporarily shrunken matrix
            double** tempMatrix = (double**)malloc((row - 1) * sizeof(double*));
            for (int j = 0; j < row - 1; j++) {
                tempMatrix[j] = (double*)malloc((col - 1) * sizeof(double));
            }

            // Assign the values to the temporary submatrix
            for (int j = 1; j < row; j++) {
                int temp_col = 0;
                for (int g = 0; g < col; g++) {
                    if (g != i) {
                        tempMatrix[j - 1][temp_col++] = matrix[j][g]; 
                    }
                }
            }

            // Call back the function with the correct - or + signage
            if (i % 2 == 0) {
                determinant += matrix[0][i] * findDeterminant(tempMatrix, row - 1, col - 1);
            } else {
                determinant -= matrix[0][i] * findDeterminant(tempMatrix, row - 1, col - 1);
            } 

            // Clean up the temp Matrix
            for (int j = 0; j < row - 1; j++) {
                free(tempMatrix[j]);
            }
            free(tempMatrix);

        }
    }

    return determinant;
}

struct Matrix matrixSetUp(FILE* fp) {
    struct Matrix mat;
/*
This function reads the size of the matrix and creates it from the values read from the file
@param fp: is the file pointer from the file that was open
@return mat struct for the values of the matrix, row, and col
*/

    // Read the matrix cols and rows
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%lf", &mat.rows);
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%lf", &mat.cols);

    // Allocate the memory for the matrix
    mat.matrix = (double **)malloc(mat.rows * sizeof(double *));
    for (int i = 0; i < mat.rows; i++) {
        mat.matrix[i] = (double *)malloc(mat.cols * sizeof(double));
    }

    // Read the matrix
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            fscanf(fp, "%lf", &mat.matrix[i][j]);
        }
    }

    return mat;
}

void deleteMatrix(struct Matrix mat) {
/*
This function clears the memory of our matrix
@param mat: for our matrix struct
*/
    // Free the matrix
    for (int i = 0; i < mat.rows; i++) {
        free(mat.matrix[i]);
    }
    free(mat.matrix);
}
