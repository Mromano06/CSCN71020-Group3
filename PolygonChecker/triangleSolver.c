#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {

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
	if ((side1 <= 0 || side2 <= 0 || side3 <= 0) && largestSide < (side1 + side2 + side3)) {

		result = "Not a triangle";

	}
	else if (side1 == side2 && side1 == side3) {

		result = "Equilateral triangle";

	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)
		|| (side2 == side3 && side2 != side1))
	{

		result = "Isosceles triangle";

	}
	else {

		result = "Scalene triangle";

	}

	return result;
}

void getTrangleAngles(int side1, int side2, int side3) {

	int a = side1, b = side2, c = side3;

	float angle1 = acos((b * b + c * c - a * a) / (2 * b * c));  // Angle opposite side a

	float angle2 = acos((a * a + c * c - b * b) / (2 * a * c));  // Angle opposite side b

	float angle3 = acos((a * a + b * b - c * c) / (2 * a * b));  // Angle opposite side c


	printf("Angle A: %f degrees\n", rad_to_deg(angle1));

	printf("Angle B: %f degrees\n", rad_to_deg(angle2));

	printf("Angle C: %f degrees\n", rad_to_deg(angle3));

}