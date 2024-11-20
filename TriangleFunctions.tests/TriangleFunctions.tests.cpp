#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);
extern "C" double getTriangleAngles(int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleFunctionstests
{
	TEST_CLASS(TriangleFunctionstests)
	{
	public:
		
		TEST_METHOD(SideLengthsFourFiveSix_ReturnProperTriangle_AnglesTotalEqual180)
		{
			double expected = 180.0, actual = 0;
			int s1 = 4, s2 = 5, s3 = 6;
			actual = getTriangleAngles(s1, s2, s3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SideLengthsOneFiveSeven_ReturnImpossibleTriangle_ReturnNegative1)
		{
			double expected = -1.0, actual = 0;
			int s1 = 1, s2 = 5, s3 = 7;
			actual = getTriangleAngles(s1, s2, s3);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SideLengths101_102_103_ReturnProperTriangle_AnglesTotalEqual180)
		{
			double expected = -1.0, actual = 0;
			int s1 = 101, s2 = 102, s3 = 13;
			actual = getTriangleAngles(s1, s2, s3);
			Assert::AreEqual(expected, actual);
		}
	};
}