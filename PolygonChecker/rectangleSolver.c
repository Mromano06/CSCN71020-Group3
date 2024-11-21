#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "main.h"
#include "rectangleSolver.h"

int compare(const void* a, const void* b) {
    
    int* x = (int*)a; // pointers to first and second values 
    int* y = (int*)b;

    
    if (x[0] != y[0]) {     // if values are not the same then sort normally (via x values)
        return x[0] - y[0];
    }
    else {
        return x[1] - y[1]; // If values are the same, compare second values (the y's)
    }

 }

void assignRecCorner(int* rectanglePoints) {
  
    qsort(rectanglePoints, REC_POINTS, 2 * sizeof(int), compare);

    printf("Sorted array: \n");
    for (int i = 0; i < REC_POINTS * 2; i += 2) {
            printf("(%d, %d) ", rectanglePoints[i], rectanglePoints[i + 1]);
        }
}

void findRecSideLengths(int* rectanglePoints, double* rectangleSides) {
    
    int length = 0;

    for (int i = 0; i < REC_POINTS + 1; i += 4) { // finding side length for height (+1 so all values can be reached)
        double x = pow((rectanglePoints[2 + i] - rectanglePoints[0 + i]), 2); // (x2 - x1) ^ 2
        double y = pow((rectanglePoints[3 + i] - rectanglePoints[1 + i]), 2); // (y2 - y1) ^ 2

        double sideLength = sqrt(x + y);
        rectangleSides[length++] = sideLength; // save the side lengths to an array for later functions

        printf("Side length: %f\n", sideLength);
    }

    for (int i = 0; i < REC_POINTS; i += 2) {    // finding side length for width
        double x = pow((rectanglePoints[4 + i] - rectanglePoints[0 + i]), 2); // (x2 - x1) ^ 2
        double y = pow((rectanglePoints[5 + i] - rectanglePoints[1 + i]), 2); // (y2 - y1) ^ 2

        double sideLength = sqrt(x + y);
        rectangleSides[length++] = sideLength;

        printf("Side length: %f\n", sideLength);
    }

    for (int i = 0; i < 4; i++) {
        printf("%lf, ", rectangleSides[i]);
    }

}

bool rectANGLES(double* rectangleSides) {

    for (int i = 0; i < 2; i++) { // check if height lengths are the same 
        
        if (rectangleSides[i] == rectangleSides[i + 1])
    }

}