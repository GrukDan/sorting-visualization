#include "ArrayHandler.h"

int * ArrayHandler::intArray(int size)
{
	if (size > 0) {
		// определяем переменные
		int* array = new int[size];
		int i;

		srand(time(0)); // инициализация генерации случайных чисел

		for (i = 0; i < size; i++)
			array[i] = 1 + rand() % 400;
		return array;
	}
	else
	{
		throw std::exception("array's size isn't valid");
	}
}

double * ArrayHandler::doubleArray(int size)
{
	if (size > 0) {
		double* array = new double[size];
		int i;

		srand(time(0)); // инициализация генерации случайных чисел

		for (i = 0; i < size; i++)
			array[i] = 1.0 + 4.0 * rand() / (float)RAND_MAX;
		return array;
	}
	else
	{
		throw std::exception("array's size isn't valid");
	}
}