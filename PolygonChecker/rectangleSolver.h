#pragma once

int compare(const void* a, const void* b);

void assignRecCorner(int* rectanglePoints);

void findRecSideLengths(int* rectanglePoints, double* rectangleSides);
void rectangleChecker(double* rectangleSides);

double rectangleHypo(double* rectangleSides, double* rectangleHypotenuse);
double rectANGLES(double* rectangleSides, double* rectangleHypotenuse);
void recArea(double* rectangleSides, bool* rectANGLES);