#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
/*
The struct of our program for the values of each point
Has x for the x-cord
Has y for the y-cord
*/
    int x; 
    int y;
} Point;

double distance(Point p1, Point p2) {
/*
This function simply returns the distance between the two points
@param p1: x and y of point 1
@param p2: x and y of point 2
@returns: the distance between the two points using pythagorean
*/
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
void calculate_perimeter(const char* file_name) {
/*
This function calculates the perimeter of the shape
@param file_name: is the file that we are reading
@returns nothing
*/
    // If there is an empty file, quit
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        return;
    }

    int num_points;
    fread(&num_points, sizeof(int), 1, file);
    // There should not be less than 3 points
    if (num_points < 3) {
        fclose(file);
        return;
    }

    // Allocate memory for the number of points there are
    Point* points = (Point*)malloc(num_points * sizeof(Point));
    
    // If there are no points at all, quit
    if (points == NULL) {
        fclose(file);
        return;
    }

    // Read through for the rest of the cords
    for (int i = 0; i < num_points; i++) {
        fread(&points[i], sizeof(Point), 1, file);
        points[i].x = (double)points[i].x;
        points[i].y = (double)points[i].y;
    }
    fclose(file);

    // Calculate the perimeter
    double perimeter = 0;
    for (int i = 0; i < num_points; i++) {
        perimeter += distance(points[i], points[(i + 1) % num_points]);
    } // We go back to find distance from the first point and the last point with % num_points

    // Output the perimeter
    printf("The perimeter is %.2lf\n", perimeter);

    // Free the allocated memory
    free(points);
}

int main(int argc, char** argv) {
/*
Reads commandline to receive the file name and command
As well as organizes the program/gets the program started
@param: argc is the command
@param: argv[1] is the file
@returns 0 for completion
*/
    calculate_perimeter(argv[1]);

    return 0;
}