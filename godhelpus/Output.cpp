#include "Output.h"
#include "conio.h"

void Output::ccol() { //словарь для выделения цветом
	colours["int"] = "\x1b[1;34mint\x1b[1;0m";
	colours["double"] = "\x1b[1;34mdouble\x1b[1;0m";
	colours["float"] = "\x1b[1;34mfloat\x1b[1;0m";
	colours["string"] = "\x1b[38;5;043mstring\x1b[1;0m"; 
	colours["for"] = "\x1b[38;5;135mfor\x1b[1;0m";
	colours["char"] = "\x1b[1;34mchar\x1b[1;0m";
	colours["void"] = "\033[1;94mvoid\033[1;0m"; 
	colours["cout"] = "\x1b[1;33mcout\x1b[1;0m";
	colours["printf"] = "\x1b[1;33mprintf\x1b[1;0m";
	colours["if"] = "\x1b[38;5;135mif\x1b[1;0m";
	colours["else"] = "\x1b[38;5;135melse\x1b[1;0m";
	colours["break"] = "\x1b[38;5;135mbreak\x1b[1;0m";
	colours["continue"] = "\x1b[38;5;135mcontinue\x1b[1;0m";
	colours["using"] = "\x1b[1;34musing\x1b[1;0m";
	colours["namespace"] = "\x1b[1;34mnamespace\x1b[1;0m";
}
void Output::print() {
	ccol();
	inicheck();
	for (string elem : allsorted) {
		int k = 0;
		for (auto el : colours) {
			if (elem == el.first) {
				cout << el.second;
				k = 1;
				break;
			}
		}
		for (string s : namesint)
		{
			if (elem == s) {
				cout << "\033[1;32m";
				cout << s;
				cout << "\033[1;0m";
				k = 1;
				break;
			}
		}
		if (k == 0) 
			cout << elem;
	}
	cout << "\033[1;31;5m";
	bracketcheck();
	cout << "\033[1;0m\n";
	cout << "\033[1;31;5m";
	cout << "\033[1;0m\n";
	conbreakcheck();
	/*
	cout << "\033[1;31;5m";
	maincheck();
	cout << "\033[1;0m\n";
	*/
}
void Output::out(char c[20]) {
	wordsep(c);
	print();
	system("pause");
}