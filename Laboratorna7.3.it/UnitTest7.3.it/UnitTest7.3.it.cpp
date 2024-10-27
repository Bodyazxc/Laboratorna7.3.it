#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna7.3.it/Laboratorna7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73it
{
	TEST_CLASS(UnitTest73it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 2;
            const int colCount = 3;

            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 2; a[0][1] = 4; a[0][2] = 6;
            a[1][0] = 1; a[1][1] = -2; a[1][2] = 3;

            SortRows(a, rowCount, colCount);

            Assert::AreEqual(1, a[0][0]);
            Assert::AreEqual(4, a[1][1]);
            Assert::AreEqual(2, a[1][0]);
            Assert::AreEqual(6, a[1][2]);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
