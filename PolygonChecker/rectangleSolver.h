#pragma once

int compare(const void* a, const void* b);

void assignRecCorner(int* rectanglePoints);
void findRecSideLengths(int* rectanglePoints, double* rectangleSides);
void rectangleChecker(double* rectangleSides);
double rectangleHypo(double* rectangleSides, double* rectangleHypotenuse);