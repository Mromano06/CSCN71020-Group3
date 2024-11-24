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

    if (rectanglePoints[7] > rectanglePoints[1]) { // swapping corner 3 & 4 when misplaced
        int temp1 = rectanglePoints[6];
        int temp2 = rectanglePoints[7];

        rectanglePoints[6] = rectanglePoints[4]; // swapping x values
        rectanglePoints[7] = rectanglePoints[5]; // swapping y values

        rectanglePoints[4] = temp1; // swapping x values with temps
        rectanglePoints[5] = temp2; // swapping y values with temps
    }

    printf("Sorted array: \n");
    for (int i = 0; i < REC_POINTS * 2; i += 2) {
            printf("(%d, %d) ", rectanglePoints[i], rectanglePoints[i + 1]);
        }
}

void findRecSideLengths(int* rectanglePoints, double* rectangleSides) {
    
    int length = 0;

    for (int i = 0; i < 5; i += 2) { // finding side length for height (+1 so all values can be reached)
        double x = pow((rectanglePoints[2 + i] - rectanglePoints[0 + i]), 2); // (x2 - x1) ^ 2
        double y = pow((rectanglePoints[3 + i] - rectanglePoints[1 + i]), 2); // (y2 - y1) ^ 2

        double sideLength = sqrt(x + y);
        rectangleSides[length++] = sideLength; // save the side lengths to an array for later functions

        printf("Side length: %.2f\n", sideLength);
    }
 
        double x = pow((rectanglePoints[6] - rectanglePoints[0]), 2); // (x2 - x1) ^ 2
        double y = pow((rectanglePoints[7] - rectanglePoints[1]), 2); // (y2 - y1) ^ 2

        double sideLength = sqrt(x + y);
        rectangleSides[length++] = sideLength; // save the side lengths to an array for later functions

        printf("Side length: %.2f\n", sideLength);


    for (int i = 0; i < 4; i++) {
        printf("%.2lf, ", rectangleSides[i]);
    }

}

double rectangleHypo(double* rectangleSides, double* rectangleHypotenuse) {

    int hypo = 0;

    for (int i = 0; i < REC_POINTS - 1; i++) {   // finding the hypotenuse of sides (1, 2), (2, 3), and (3, 4)
        double hypotenuse = sqrt(pow(rectangleSides[0 + i], 2) + pow(rectangleSides[1 + i], 2)); 

        rectangleHypotenuse[hypo++] = hypotenuse; // save the hypotenuse to an array
    }
        
        double hypotenuse = sqrt(pow(rectangleSides[3], 2) + pow(rectangleSides[0], 2)); // finding the hypotenuse of side (4, 1)
        rectangleHypotenuse[hypo++] = hypotenuse;
}

void rectANGLES(double* rectangleSides, double* rectangleHypotenuse) {
    
    void findRecSideLengths(int* rectanglePoints, double* rectangleSides);

    double left   = rectangleSides[0]; // set variables of the rectangles sides
    double right  = rectangleSides[1];
    double bottom = rectangleSides[2];
    double top    = rectangleSides[3];

    double hypo = rectangleHypo(rectangleSides, rectangleHypotenuse);

    double total = 0;

    double angle1 = acos((right * right + hypo * hypo - left * left) / (2 * right * hypo));	  // Angle opposite
 
    /*
    angle1 = angle1 * (180.0 / M_PI);
    angle2 = angle2 * (180.0 / M_PI);
    angle3 = angle3 * (180.0 / M_PI);				// converts all values to degrees
    */

    printf("Angle A: %.2f degrees\n", angle1);		// printing all values
    // printf("Angle B: %.2f degrees\n", angle2);
    // printf("Angle C: %.2f degrees\n\n", angle3);

    // total = angle1 + angle2 + angle3;

    // if (total != 360 || left != 90 || right != 90 || bottom != 90 || top != 90)
        // return(-1);

    // return ((int)total);

}

