#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "main.h"
#include "rectangleSolver.h"

int compare(const void* a, const void* b) {
    
    int* x = (int*)a; // pointers to first and second values 
    int* y = (int*)b;

    
    if (x[0] != y[0]) { // if values are not the same then sort normally (via x values)
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

void findRecSideLengths(int* rectanglePoints) {

    for (int i = 0; i < REC_POINTS * 2; i += 2) {
        double x = pow((rectanglePoints[2 + i] - rectanglePoints[0 + i]), 2); // (x2 - x1) ^ 2
        double y = pow((rectanglePoints[3 + i] - rectanglePoints[1 + i]), 2); // (y2 - y1) ^ 2

        double sideLength = sqrt(x + y);

        printf("Side length: %f\n", sideLength);
    }
}