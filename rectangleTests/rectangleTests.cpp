#include "pch.h"
#include "CppUnitTest.h"
extern "C" void assignRecCorner(int* rectanglePoints);
extern "C" void findRecSideLengths(int* rectanglePoints, double* rectangleSides);
extern "C" double rectangleHypo(double* rectangleSides, double* rectangleHypotenuse);
extern "C" bool rectANGLES(double* rectangleSides, double* rectangleHypotenuse);
extern "C" void recArea(double* rectangleSides, bool* rectANGLES);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangleTests {
	TEST_CLASS(rectangleTests) {
    public:
	// naming convention: (test_description_expected)
	TEST_METHOD(FindRectangleSideLengths_ValidInput_ReturnsCorrectLengths) {
		int points[] = { 1, 1, 1, 4, 4, 4, 4, 1 };
		double sides[4] = { 0 };
		double expected[] = { 3.0, 3.0, 3.0, 3.0 };

        {
        }

        {
        }

        }

        {
        }

        {
        }
	TEST_METHOD(AssignRectangleCorners_AlreadySorted_NoChange)
	{
		int points[] = { 1, 1, 1, 4, 4, 4, 4, 1 }; // Already sorted rectangle points
		int expected[] = { 1, 1, 1, 4, 4, 4, 4, 1 };

		assignRecCorner(points);

        {

        }
        }
    };
}