#include "Main.h"

using namespace std::placeholders;

void clear_screen()
{
#ifdef WINDOWS
	std::system("cls");
#else
	// Assume POSIX
	std::system("clear");
#endif
}

int main(void) {
	
	int arraysSize = 20;
	int pause = 2300;
	int width = 40, height = 30;

	ArrayHandler arrayHandler;
	FunctionCaller functionCaller;

	PlaySound("D:/Projects/TestCppSpeed/infinity.wav", NULL, SND_ASYNC);

	while (true) {

		std::cout << "Input arrays's size(better value from 10 to 25):";
		while (!(std::cin >> arraysSize) || arraysSize<0) {
			std::cin.clear(); 
			while (std::cin.get() != '\n' ) continue; 
		}

		ConsolePainter* consolePainterPtr = new ConsolePainter(width, height);
		Sorting sorting(*consolePainterPtr);

		int* startArray = arrayHandler.intArray(arraysSize);
		int* testArray = new int[arraysSize];

		auto bubbleCallback = std::bind(&Sorting::bubblesort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(bubbleCallback, testArray, &testArray[arraysSize - 1], pause, "bubbleSort");

		auto shakerCallback = std::bind(&Sorting::shakersort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(shakerCallback, testArray, &testArray[arraysSize - 1], pause, "shakerSort");

		auto combCallback = std::bind(&Sorting::combsort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(combCallback, testArray, &testArray[arraysSize - 1], pause, "combSort");

		auto insertCallback = std::bind(&Sorting::insertionsort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(insertCallback, testArray, &testArray[arraysSize - 1], pause, "insertSort");

		auto shellCallback = std::bind(&Sorting::shellsort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(shellCallback, testArray, &testArray[arraysSize - 1], pause, "shellSort");

		auto gnomeCallback = std::bind(&Sorting::gnomesort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(gnomeCallback, testArray, &testArray[arraysSize - 1], pause, "gnomeSort");

		auto quickCallback = std::bind(&Sorting::quicksort, sorting, _1, _2);
		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		functionCaller.callfunction(quickCallback, testArray, &testArray[arraysSize - 1], pause, "quickSort");

		arrayHandler.arrayCopy(startArray, testArray, arraysSize);
		auto begin = std::chrono::steady_clock::now();
		sorting.heapsort(testArray, arraysSize);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << std::endl << "The time of <" << "heapSort" << ">:" << elapsed_ms.count() << " ms\n";

		delete[] startArray;
		delete[] testArray;
		delete consolePainterPtr;

		system("pause");
	}
	return 0;
}
