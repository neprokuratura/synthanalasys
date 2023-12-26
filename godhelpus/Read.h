#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Read
{
protected:
    char all[1000];
    string allsorted[1000];//все
    string words[1000];//все без табов и пробелов
    int wordcount = 0;
public:
    int readall(char []);
    int wordsep(char []);
};

