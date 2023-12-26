#include "Read.h"
#include <vector>
#include <string>
using namespace std;

class Processing : public Read
{
protected:
	string variablenames[7] = { "int", "char", "string", "bool", "float", "double","void"};
	string allnames[11] = { "int", "char", "string", "bool", "float", "double", "for","while","break","continue","do"};
	string symbols[19] = {"+","-","*","/",">","<",">=","<=","==","+=","-=", "||","&&"};
	vector <string> namesint{};
public:
	void bracketcheck();
	void conbreakcheck();
	void inicheck();
	void maincheck();
};
