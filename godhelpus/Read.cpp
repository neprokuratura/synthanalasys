#include "Read.h"
#include <iostream>
#include <string>
#include <fstream>
int Read::readall(char c[20]) {
	FILE* f;
	char v;
	int i = 0;
	f = fopen(c, "r");
	while ((v = getc(f)) != EOF) {
		all[i] = v;
		i++;
	}
	fclose(f);
	return i;
}
int Read::wordsep(char c[20]) {
	int i = readall(c);
	int i1 = 0;
	int i2 = 0;
	char forswitch[]{' ',';','(',')','{','}','\n','\t','"',','};//для кейса
	while (i1 < i) {
		int a = 52;
		for (int k = 0; k < 10; k++) {
			if (all[i1] == forswitch[k]) {
				a = 0;
				break;
			}
		}
		switch (a) {//ввод в массив со всем
			case 0:
				i2++;
				allsorted[i2] += all[i1];
				i2++;
				break;
			default:
				allsorted[i2] += all[i1];
		}
		i1++;
	}
	for (int i = 0; i < i2; i++) {
		if (allsorted[i] != " " && allsorted[i] != "" && allsorted[i] != "\t") {
			words[wordcount] = allsorted[i];
			wordcount++;
		}
	}
	return i2;
}
