#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

#define TRI_POINTS		3 // defining common usages
#define REC_POINTS		4

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf_s("Rectangle selected.\n"); // Added rectangle case
			int rectanglePoints[REC_POINTS * 2] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);

			// char* result = analyzeRectangle(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2]);
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[TRI_POINTS] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
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

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int getRectanglePoints(int* rectanglePoints) {
	printf_s("Enter the 4 corners of your rectangle in the formate of x y coordinates (only ints!): "); // Each point is an x, y pair.
	
	for (int i = 0; i < (REC_POINTS * 2); i += 2) // iterate through inputs, adding them to the rectanglePoints array
	{
		scanf_s("%d, %d", &rectanglePoints[i], &rectanglePoints[i+1]);
	}
	return rectanglePoints;
}