#include "pch.h"
#include "CppUnitTest.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

namespace Asn2Test
{
	TEST_CLASS(RectangleTest)
	{
	public:
		
		TEST_METHOD(TestgetPerimeter)
		{
			int length = 5;
			int width = 10;

			int actualPerimeter = getPerimeter(&length, &width);

			int expectedPerimeter = 2 * (length + width);
			Assert::AreEqual(expectedPerimeter, actualPerimeter);

		}
		TEST_METHOD(TestgetArea)
		{
			int length = 5;
			int width = 10;

			
			int actualArea = getArea(&length, &width);

			
			int expectedArea = length * width;
			Assert::AreEqual(expectedArea, actualArea);
		}
		TEST_METHOD(TestSetLength_ValidInput)
		{
			
			int length = 0;
			int input = 25; 

			
			setLength(input, &length);

			
			Assert::AreEqual(input, length);
		}
		TEST_METHOD(TestSetLength_MinimumInput)
		{
			int length = 0;
			int input = 1; // Minimum valid input

			// Execution
			setLength(input, &length);

			// Assert
			Assert::AreEqual(input, length);
		}
		TEST_METHOD(TestSetLength_InvalidInput)
		{
			int length = 50; // Start with a valid length
			int input = 100; // Invalid input

			// Execution
			setLength(input, &length);

			// Assert
			Assert::AreEqual(50, length);
		}
		TEST_METHOD(TestSetWidth_ValidInput)
		{
			int width = 0;
			int input = 75;

			// Execution
			setWidth(input, &width);

			// Assert
			Assert::AreEqual(input, width);
		}
		TEST_METHOD(TestSetWidth_MaximumInput)
		{
			int width = 0;
			int input = 99; // Maximum valid input

			// Execution
			setWidth(input, &width);

			// Assert
			Assert::AreEqual(input, width);
		}
		TEST_METHOD(TestSetWidth_IvalidInput)
		{
			int width = 30; // Start with a valid width
			int input = -10; // Invalid input

			// Execution
			setWidth(input, &width);

			// Assert
			Assert::AreEqual(30, width);
		}
	};
}
