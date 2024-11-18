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
	};
}