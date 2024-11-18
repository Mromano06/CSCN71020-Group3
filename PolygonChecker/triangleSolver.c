#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if ((side1 <= 0 || side2 <= 0 || side3 <= 0) || largestSide > (side1 + side2 + side3)) {			// now also checks if other sides larger than hypotonuse

		result = "Not a triangle\n";

	}
	else if (side1 == side2 && side1 == side3) {														// checks for equalatiral

		result = "Equilateral triangle\n";

	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{

		result = "Isosceles triangle\n";

	}
	else {

		result = "Scalene triangle\n";

	}

	return result;
}

void getTriangleAngles(int side1, int side2, int side3) {

	double a = side1, b = side2, c = side3;

	double angle1 = acos((b * b + c * c - a * a) / (2 * b * c));										// Angle opposite side a
	double angle2 = acos((a * a + c * c - b * b) / (2 * a * c));										// Angle opposite side b
	double angle3 = acos((a * a + b * b - c * c) / (2 * a * b));										// Angle opposite side c

	angle1 = angle1 * (180.0 / M_PI);
	angle2 = angle2 * (180.0 / M_PI);
	angle3 = angle3 * (180.0 / M_PI);																	// converts all values to degrees

	printf("Angle A: %.2f degrees\n", angle1);															// printing all values
	printf("Angle B: %.2f degrees\n", angle2);
	printf("Angle C: %.2f degrees\n\n", angle3);

}