#pragma once
#include <map>
#include "Processing.h"

class Output : public Processing
{
public:
	void ccol();
	void print();
	void out(char[20]);
	std::map <string, string> colours;
};

