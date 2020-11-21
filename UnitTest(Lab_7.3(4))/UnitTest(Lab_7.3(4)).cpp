#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3(4)/Lab_7.3(4).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab734
{
	TEST_CLASS(UnitTestLab734)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int const line = 3;
			int const column = 3;
			int** matriz = new int* [line];
			for (int index = 0; index < line; index++)
				matriz[index] = new int[column];
			int* masuv_min = new int[line];
			int* masuv_max = new int[column];
			matriz[0][0] = 1; matriz[0][1] = 2;matriz[0][2] = 3;matriz[1][0] = 4;matriz[1][1] = 5;matriz[1][2] = 6;matriz[2][0] = 7;matriz[2][1] = 8;matriz[2][2] = 9;
			point_sidlova(matriz, line, column, 0, 1, masuv_min, matriz[0][0]);
			point_sidlova1(matriz, line, column, 1, 0, masuv_max, matriz[0][0]);
			point_sidlova2(matriz, line, column, 0, 0, masuv_min, masuv_max);
			Assert::AreEqual(matriz[2][0], 0);
			delete[] matriz;
			delete[] masuv_min;
			delete[] masuv_max;
		}
	};
}
