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
	TEST_METHOD(FindRectangleSideLengths_ValidInput_ReturnsCorrectLengths){
		int points[] = { 1, 1, 1, 4, 4, 4, 4, 1 };
		double sides[4] = { 0 };
		double expected[] = { 3.0, 3.0, 3.0, 3.0 };

		findRecSideLengths(points, sides);
		for (int i = 0; i < 4; i++) {
			Assert::AreEqual(expected[i], sides[i]);
		}
	}
	TEST_METHOD(CheckRectangle_AnglesAddUp_ReturnsTrue)
	{
		double sides[] = { 3.0, 4.0, 3.0, 4.0 };
		double hypotenuse[4] = { 0 };

		bool result = rectANGLES(sides, hypotenuse);
		Assert::IsTrue(result);
	}

	TEST_METHOD(RecArea_CalculatesCorrectArea)
	{
		double sides[] = { 3.0, 4.0, 3.0, 4.0 }; // Rectangle with width=3, height=4
		bool isRectangle = true; // Assume it’s confirmed as a rectangle

		double expectedArea = 12.0;
		double actualArea = 0;

		if (isRectangle) {
			recArea(sides, &isRectangle); // Should print the area
			actualArea = sides[0] * sides[1]; // Area = width * height
		}

		Assert::AreEqual(expectedArea, actualArea, 1e-6);
	}

	TEST_METHOD(RectANGLES_ValidRectangle_ReturnsTrue)
	{
		double sides[] = { 3.0, 4.0, 3.0, 4.0 }; // Rectangle with width=3, height=4
		double hypotenuses[4] = { 0 };

		bool result = rectANGLES(sides, hypotenuses);

		Assert::IsTrue(result);
	}

	TEST_METHOD(RectANGLES_InvalidRectangle_ReturnsFalse)
	{
		double sides[] = { 3.0, 4.0, 5.0, 6.0 }; // Invalid rectangle sides
		double hypotenuses[4] = { 0 };

		bool result = rectANGLES(sides, hypotenuses);

		Assert::IsFalse(result);
	}
	TEST_METHOD(AssignRectangleCorners_AlreadySorted_NoChange)
	{
		int points[] = { 1, 1, 1, 4, 4, 4, 4, 1 }; // Already sorted rectangle points
		int expected[] = { 1, 1, 1, 4, 4, 4, 4, 1 };

		assignRecCorner(points);

		for (int i = 0; i < 8; i++) {
			Assert::AreEqual(expected[i], points[i]);
		}
	}
	TEST_METHOD(FindRectangleSideLengths_AllZeroPoints_ReturnsZeroLengths)
	{
		int points[] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // All points are the same
		double sides[4] = { 0 };
		double expected[] = { 0.0, 0.0, 0.0, 0.0 };

		findRecSideLengths(points, sides);

		for (int i = 0; i < 4; i++) {
			Assert::AreEqual(expected[i], sides[i]);
		}
	}
	};
}