#include "pch.h"
#include "CppUnitTest.h"
#include "../labbbb.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(calculateTests)
	{
	public:
		// n < 2
		TEST_METHOD(checkN_get0_exceptionThrown)
		{
			int n = 0;
			try {
				checkN(n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			} 
		}
		//n > 1
	public:
		TEST_METHOD(checkN_get5_exceptionNotThrown) {
			int n = 5;
			try {
				checkN(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	public:		//b < a
		TEST_METHOD(checkRangeParams_getA11andB3_exceptionThrown) {
			int a = 11;
			int b = 3;
			int step = 1;
			try {
				checkRangeParams(a, b, step);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:		//b > a
		TEST_METHOD(checkRangeParams_getA5andB8_exceptionNotThrown) {
			int a = 5;
			int b = 8;
			int step = 1;
			try {
				checkRangeParams(a, b, step);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	public:		//step < 0
		TEST_METHOD(checkRangeParams_getStepMinus2_exceptionThrown) {
			int a = 5;
			int b = 8;
			int step = -2;
			try {
				checkRangeParams(a, b, step);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
						//ans 5
	public:
		TEST_METHOD(calcFunc1_get3andMinus4_5returned) {
			int n = 3;
			int x = -4;
			int expected = 5;

			int actual = calcFunc1(n, x);
			Assert::AreEqual(expected, actual);
		}
						//ans 34
	public:
		TEST_METHOD(calcFunc1_get6and23_125returned) {
			int n = 2;
			int x = 23;
			int expected = 304;

			int actual = calcFunc1(n, x);
			Assert::AreEqual(expected, actual);
		}
	};
}
