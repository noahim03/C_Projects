//This code uses the Monte Carlo Method to find an estimate for pi.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_double(double low, double high) {
    /*
    generate a random double between low and high inclusive
    @low: the lowest possible double that can be generated
    @high: the highest possible double that can be generated
    @returns: a random number between low and high
    */
    return low + ((double) rand()) / (((double) RAND_MAX / (high - low)));
}

int num_inside_circle(double x, double y) { //Check if the random point is inside of the circle. Returns 1 if the point is inside the circle. Return 0 if not. 
    if ((x * x) + (y * y) < 1) {
        return 1;
    }
    else {
        return 0;
    }
}

double pi_estimate(int iterations) { //Calculates the estimate of pi. 
    int points_in_circle = 0;//Counts how many points are inside of the circle. 
    int i;

    for (i = 0; i < iterations; ++i) { //Loops through the number of iterations to get random points inbetween -1.0 to 1.0
        double x = rand_double(-1.0, 1.0);
        double y = rand_double(-1.0, 1.0); 
        if (num_inside_circle(x, y)) { //If the point is inside of the circle, then it adds 1 too the points in the circle
            ++points_in_circle;
        }
    }
    return (4.0 * ((double)points_in_circle / (double)iterations)); //Equation to estimate pi. Gets the amount of points that were in the circle. Divided by how many iterations there were. Multiplied by 4.
}


int main () {
    int seed, iterations; //My variables

    printf("Enter the seed for the random number generator: "); //Ask user for a random seed
    scanf("%d", &seed);//reads the number

    printf("Enter the number of iterations to run: ");//Asks user for the amount of iterations
    scanf("%d", &iterations);//reads the number

    srand(seed);//Starts the random number generator

    double pie_estimate = pi_estimate(iterations); //Calls the pi_estimate function to find the value of pi
    printf("The value of pi is %.2lf.", pie_estimate); //prints the esitmate of pi to the hundredths place

    return 0;
}