#pragma once

#include "Main.h"

using SortHandler = std::function<void(int * l, int * r)>;

class FunctionCaller {
public:
	void callfunction(const SortHandler &handler, int* l, int* r, int pause, std::string sortingName);
};