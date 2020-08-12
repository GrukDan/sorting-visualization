#pragma once
#include "Main.h"
#include "ConsolePainter.h"


class Sorting {
private:
	ConsolePainter &consolePainter;
	void siftDown(int *numbers, int root, int bottom);
public:
	Sorting(ConsolePainter &consolePainter) :consolePainter(consolePainter) {}
	void bubblesort(int * l, int * r);
	void shakersort(int * l, int * r);
	void combsort(int * l, int * r);
	void insertionsort(int * l, int * r);
	void shellsort(int * l, int * r);
	void gnomesort(int * l, int * r);
	void quicksort(int * l, int * r);
	void heapsort(int *numbers, int array_size);
};

