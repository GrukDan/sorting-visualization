#include "Sorting.h"


void Sorting::siftDown(int * numbers, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
				  // Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // если мы в последнем ряду,
			maxChild = root * 2;    // запоминаем левый потомок
									// иначе запоминаем больший потомок из двух
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}

void Sorting::bubblesort(int * l, int * r)
{

	int sz = r - l;
	if (sz <= 1) return;
	bool b = true;
	while (b) {
		b = false;
		for (int* i = l; i + 1 < r; i++) {
			if (*i > *(i + 1)) {
				std::swap(*i, *(i + 1));
				b = true;
			}
			consolePainter.draw(l, sz);
		}
		r--;
		consolePainter.draw(l, sz);
	}
}

void Sorting::shakersort(int * l, int * r)
{
	int sz = r - l;
	if (sz <= 1) return;
	bool b = true;
	int* beg = l - 1;
	int* end = r - 1;
	while (b) {
		b = false;
		beg++;
		for (int* i = beg; i < end; i++) {
			if (*i > *(i + 1)) {
				std::swap(*i, *(i + 1));
				b = true;
			}
			consolePainter.draw(l, sz);
		}
		if (!b) break;
		end--;
		for (int* i = end; i > beg; i--) {
			if (*i < *(i - 1)) {
				std::swap(*i, *(i - 1));
				b = true;
			}
			consolePainter.draw(l, sz);
		}
		consolePainter.draw(l, sz);
	}
}

void Sorting::combsort(int * l, int * r)
{
	int sz = r - l;
	if (sz <= 1) return;
	double k = 1.2473309;
	int step = sz - 1;
	while (step > 1) {
		for (int* i = l; i + step < r; i++) {
			if (*i > *(i + step))
				std::swap(*i, *(i + step));
			consolePainter.draw(l, sz);
		}
		step /= k;
		consolePainter.draw(l, sz);
	}
	bool b = true;
	while (b) {
		b = false;
		for (int* i = l; i + 1 < r; i++) {
			if (*i > *(i + 1)) {
				std::swap(*i, *(i + 1));
				b = true;
			}
			consolePainter.draw(l, sz);
		}
		consolePainter.draw(l, sz);
	}
}

void Sorting::insertionsort(int * l, int * r)
{
	int sz = r - l;
	for (int *i = l + 1; i < r; i++) {
		int* j = i;
		while (j > l && *(j - 1) > *j) {
			std::swap(*(j - 1), *j);
			j--;
			consolePainter.draw(l, sz);
		}
		consolePainter.draw(l, sz);
	}
}

void Sorting::shellsort(int * l, int * r)
{

	int sz = r - l;
	int step = sz / 2;
	while (step >= 1) {
		for (int *i = l + step; i < r; i++) {
			int *j = i;
			int *diff = j - step;
			while (diff >= l && *diff > *j) {
				std::swap(*diff, *j);
				j = diff;
				diff = j - step;
				consolePainter.draw(l, sz);
			}
			consolePainter.draw(l, sz);
		}
		consolePainter.draw(l, sz);
		step /= 2;
	}
}

void Sorting::gnomesort(int * l, int * r)
{
	int sz = r - l;

	int *i = l;
	while (i < r) {
		if (i == l || *(i - 1) <= *i) i++;
		else std::swap(*(i - 1), *i), i--;
		consolePainter.draw(l, sz);
	}
}

void Sorting::quicksort(int * l, int * r)
{
	int sz = r - l;
	if (r - l <= 1) return;
	int z = *(l + (r - l) / 2);
	int* ll = l, *rr = r - 1;
	while (ll <= rr) {
		while (*ll < z) {
			ll++;
			consolePainter.draw(l, sz);
		}
		while (*rr > z) {
			rr--;
			consolePainter.draw(l, sz);
		}
		if (ll <= rr) {
			std::swap(*ll, *rr);
			ll++;
			rr--;
			consolePainter.draw(l, sz);
		}
		consolePainter.draw(l, sz);
	}
	if (l < rr) quicksort(l, rr + 1);
	if (ll < r) quicksort(ll, r);
}

void Sorting::heapsort(int * numbers, int array_size)
{
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--) {
		siftDown(numbers, i, array_size - 1);
		consolePainter.draw(numbers, array_size);
	}
	// Просеиваем через пирамиду остальные элементы
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
		consolePainter.draw(numbers, array_size);
	}
}





