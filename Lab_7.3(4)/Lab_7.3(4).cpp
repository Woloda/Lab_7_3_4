
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, int index, int index_j);
void matriz_print(int** matriz, const int line, const int column, int index, int index_j);
void point_sidlova(int** matriz, int line, const int column, int index, int index_j, int* masuv_min, int min);
void point_sidlova1(int** matriz, int line, const int column, int index, int index_j, int* masuv_max, int max);
void point_sidlova2(int** matriz, int line, const int column, int index, int index_j, int* masuv_min, int* masuv_max);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;
	using std::cin;

	int line = 3;
	int column = 3;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	matriz_create(matriz, line, column, 0, 0);
	cout << "Сформований масив: " << endl << endl;
	matriz_print(matriz, line, column, 0, 0);
	cout << endl << endl;

	int* masuv_min = new int[line];
	int* masuv_max = new int[column];

	point_sidlova(matriz, line, column, 0, 1, masuv_min, matriz[0][0]);
	point_sidlova1(matriz, line, column, 1, 0, masuv_max, matriz[0][0]);
	point_sidlova2(matriz, line, column, 0, 0, masuv_min, masuv_max);

	delete[] matriz;
	delete[] masuv_min;
	delete[] masuv_max;

	return 0;
}


void matriz_create(int** matriz, const int line, const int column, int index, int index_j)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "a[" << index << "][" << index_j << "] = ";
	cin >> matriz[index][index_j];
	if (index_j < column - 1)
		matriz_create(matriz, line, column, index, index_j + 1);
	else
		if (index < line - 1)
		{
			cout << endl;
			matriz_create(matriz, line, column, index + 1, 0);
		}
		else
			cout << endl;
}

void matriz_print(int** matriz, const int line, const int column, int index, int index_j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << matriz[index][index_j];
	if (index_j < column - 1)
		matriz_print(matriz, line, column, index, index_j + 1);
	else
		if (index < line - 1)
		{
			cout << endl;
			matriz_print(matriz, line, column, index + 1, 0);
		}
}



void point_sidlova(int** matriz, int line, const int column, int index, int index_j, int* masuv_min, int min)
{
	using std::cout;
	using std::endl;

	if ((index == 0 || index == 1 || index == 2) && index_j == 1)
		masuv_min[index] = matriz[index][0];

	if (min > matriz[index][index_j])
	{
		min = matriz[index][index_j];
		masuv_min[index] = matriz[index][index_j];
	}

	if (index_j < column - 1)
		point_sidlova(matriz, line, column, index, index_j + 1, masuv_min, min);
	else
		if (index < line - 1)
			point_sidlova(matriz, line, column, index + 1, 1, masuv_min, matriz[index + 1][0]);
		else;
}
void point_sidlova1(int** matriz, int line, const int column, int index, int index_j, int* masuv_max, int max)
{
	if ((index_j == 0 || index_j == 1 || index_j == 2) && index == 1)
		masuv_max[index_j] = matriz[0][index_j];

	if (max < matriz[index][index_j])
	{
		max = matriz[index][index_j];
		masuv_max[index_j] = matriz[index][index_j];
	}

	if (index < column - 1)
		point_sidlova1(matriz, line, column, index + 1, index_j, masuv_max, max);
	else
		if (index_j < line - 1)
			point_sidlova1(matriz, line, column, 1, index_j + 1, masuv_max, matriz[0][index_j + 1]);
		else;
}
void point_sidlova2(int** matriz, int line, const int column, int index, int index_j, int* masuv_min, int* masuv_max)
{
	using std::cout;
	using std::endl;

	if (masuv_min[index] == masuv_max[index_j])
	{
		cout << "Осідла тоска: " << masuv_min[index] << endl;
		matriz[index][index_j] = 0;  //Для юніт-тесту.
	}
	else;

	if (index_j < column - 1)
		point_sidlova2(matriz, line, column, index, index_j + 1, masuv_min, masuv_max);
	else
		if (index < line - 1)
			point_sidlova2(matriz, line, column, index + 1, 0, masuv_min, masuv_max);
		else;
}
