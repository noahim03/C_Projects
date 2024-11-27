#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

typedef struct Matrix {
    double rows;
    double cols;
    double **matrix;
}Matrix;

double findDeterminant(double** matrix, int rows, int cols); // Solve for the determinant
Matrix matrixSetUp(FILE* fp); // Set up the initial matrix read from file
void deleteMatrix(Matrix matrix); // Clear the memory for the matrix

#endif