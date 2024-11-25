#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define M_PI											3.14159265358979323846

char* analyzeTriangle(int side1, int side2, int side3) {

	if (side1 > 100 || side2 > 100 || side3 > 100)
		return("Error side lengths exceed max length\n");	

	int a = side1, b = side2, c = side3, largestSide = 0;

	if (a >= b && a >= c) {																				// find the hypotonuse
		largestSide = a;
		a = 0;
	}
	else if (b >= a && b >= c) {
		largestSide = b;
		b = 0;
	}
	else {
		largestSide = c;
		c = 0;
	}

	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0 || largestSide >= (a + b + c)) {							// now also checks if other sides larger than hypotonuse

		result = "Not a triangle\n";
		printf("Not a triangle\n");

	}
	else if (side1 == side2 && side1 == side3) {														// checks for equalatiral

		result = "Equilateral triangle\n";
		printf("Equilateral triangle\n");

	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)					// checks for icosceles
		|| (side2 == side3 && side2 != side1))
	{

		result = "Isosceles triangle\n";
		printf("Isosceles triangle");

	}
	else {

		result = "Scalene triangle\n";
		printf("Scalene triangle\n");

	}

	return result;
}

double getTriangleAngles(int side1, int side2, int side3) {

	double a = side1, b = side2, c = side3, total = 0;

	double angle1 = acos((b * b + c * c - a * a) / (2 * b * c));										// Angle opposite side a
	double angle2 = acos((a * a + c * c - b * b) / (2 * a * c));										// Angle opposite side b
	double angle3 = acos((a * a + b * b - c * c) / (2 * a * b));										// Angle opposite side c

	angle1 = angle1 * (180.0 / M_PI);
	angle2 = angle2 * (180.0 / M_PI);
	angle3 = angle3 * (180.0 / M_PI);																	// converts all values to degrees

	printf("Angle A: %.2f degrees\n", angle1);															// printing all values
	printf("Angle B: %.2f degrees\n", angle2);
	printf("Angle C: %.2f degrees\n", angle3);

	total = angle1 + angle2 + angle3;

	if (total != 180.0 || side1 > 100 || side2 > 100 || side3 > 100)
		return(-1);

	return ((int)total);

}