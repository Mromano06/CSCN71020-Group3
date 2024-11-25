#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf_s("Rectangle selected.\n\n"); // Added rectangle case

			int rectanglePoints[REC_POINTS * 2] = { 0 };
			double rectangleSides[REC_POINTS] = { 0 };
			double rectangleHypotenuse[REC_POINTS] = { 0 };

			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);

			assignRecCorner(rectanglePoints);
			findRecSideLengths(rectanglePoints, rectangleSides);
			bool isRectangle = rectANGLES(rectangleSides, rectangleHypotenuse);
			recArea(rectangleSides, &isRectangle);

			break;
		case 1:
			printf_s("Triangle selected.\n");

			int triangleSides[TRI_POINTS] = { 0 }; // changed initialization

			int* triangleSidesPtr = getTriangleSides(triangleSides);

			char* result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);
			
			getTriangleAngles(triangleSides[0], triangleSides[1], triangleSides[2]);							// prints the angles of the triangles
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("2. Rectangle\n"); // added rectangle option 
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice = 0;

	printf("Enter number: "); // fixed shapeChoice input so that it can function with numbers > 7
	if (scanf_s("%d", &shapeChoice) != 1) {
		printf("Invaild input");
		return 0;
	}
	return shapeChoice;
}

int getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle (seperated by spaces): ");
	
	if (scanf_s("%d %d %d\n", &triangleSides[0], &triangleSides[1], &triangleSides[2]) != 3) {
		printf("Input invalid");
		return 0;
	}
	return triangleSides;
}

int getRectanglePoints(int* rectanglePoints)  {// function to recive user input as cooridinates for rectangle corners
	printf_s("Enter the 4 corners of your rectangle in the formate of x y coordinates (only ints!): "); // Each point is an x, y pair.
	
	for (int i = 0; i < (REC_POINTS * 2); i += 2) {		// iterate through inputs, adding them to the rectanglePoints array
		if (scanf_s("%d %d", &rectanglePoints[i], &rectanglePoints[i + 1]) != 2) {
			printf("Input invalid");
			break;
		}
	}
	return rectanglePoints;
}
