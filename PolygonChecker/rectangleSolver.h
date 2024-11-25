#pragma once

int compare(const void* a, const void* b);

void assignRecCorner(int* rectanglePoints);

void findRecSideLengths(int* rectanglePoints, double* rectangleSides);

double rectangleHypo(double* rectangleSides, double* rectangleHypotenuse);
bool rectANGLES(double* rectangleSides, double* rectangleHypotenuse);
void recArea(double* rectangleSides, bool* rectANGLES);