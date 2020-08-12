#pragma once

#include "Main.h"

class ArrayHandler {
public:
	int* intArray(int size);
	double* doubleArray(int size);
	template<typename T> void printArray(T * printedArray, int arraysSize);
	template<typename T> void arrayCopy(T * outArray, T* copiedArray, int arraysSize);
};

template<typename T>
inline void ArrayHandler::printArray(T * printedArray, int arraysSize)
{
	if (arraysSize > 0) {
		cout << "Array of <" << typeid(T).name() << ">: ";
		for (int i = 0; i < arraysSize; i++) {
			std::cout << printedArray[i] << " ";
		}
	}
	else {
		throw std::exception("arrays size isn't valid");
	}
}

template<typename T>
inline void ArrayHandler::arrayCopy(T * outArray, T* copiedArray, int arraysSize)
{
	if (sizeof(outArray) / sizeof(outArray[0]) == sizeof(copiedArray) / sizeof(copiedArray[0])) {
		for (int i = 0; i < arraysSize; i++) {
			copiedArray[i] = outArray[i];
		}
	}
	else {
		throw std::exception("size of arrays are different...");
	}
}
