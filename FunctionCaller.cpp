#include "FunctionCaller.h"

void FunctionCaller::callfunction(const SortHandler & handler, int * l, int * r, int pause, std::string sortingName)
{
	auto begin = std::chrono::steady_clock::now();
	handler(l, r);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "The time of <" << sortingName<<">:" << elapsed_ms.count() << " ms\n";
	Sleep(pause);
}
