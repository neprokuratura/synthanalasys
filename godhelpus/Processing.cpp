#include "Processing.h"
#include <string>
#include <cctype>
void Processing::bracketcheck() {
	int brackets[4] = { };//колво скобок 
	for (string count : words) {
		if (count == "(")
			brackets[0]++;
		if (count == ")")
			brackets[1]++;
		if (count == "{")
			brackets[2]++;
		if (count == "}")
			brackets[3]++;
	}
	if (brackets[0] != brackets[1]) {
		cout << "\nНе хватает " << abs(brackets[0] - brackets[1]) << " круглых(-ой) скобок(-и)!" << endl;
	}
	if (brackets[2] != brackets[3]) {
		cout << "\nНе хватает " << abs(brackets[2] - brackets[3]) << " фигурных(-ой) скобок(-и)!" << endl;
	}
}
void Processing::conbreakcheck() {
 	int p1 = 0, p2 = 0;// p1 - { p2 - } .
	int addbr1 = 0;
	int addbr2 = 0;
	int doflag = 1;
	int fl = 0;
	int i = 0;
	vector <int> bracketpos{};
	string elem;
	string nextline = "\n";
	int lines = 1;
	for (string q : words) {
		if (i == wordcount)
			break;
		if ((q == "for")||((q == "while")&&(doflag == 1))) {
			if (words[i + 1] == "(") {
				int tempp1 = i + 2;
				for (tempp1; tempp1 < wordcount; tempp1++) {
					if (words[tempp1] == "(") { //
						addbr1++;
					}
					if (words[tempp1] == ")") {
						if (addbr1 != 0) {
							addbr1--;
						}
						else {
							if (words[tempp1 + 1] != "{") {
								int idk = tempp1+1;
								while (idk < wordcount) {
									if ((words[idk] == "\n")) {
										continue;
									}
									if ((words[idk] == "break") || (words[idk] == "continue")) {
										bracketpos.push_back(tempp1);
										bracketpos.push_back(tempp1 + 2);
										break;
									}
									else
										break;
									idk++;
								}
								break;
							}
							else {
								int p1 = tempp1+1,p = tempp1+2;
								while (p < wordcount) {
									if (words[p] == "{") {
										addbr2++;
									}
									if (words[p] == "}") {
										if (addbr2 != 0) {
											addbr2--;
										}
										else {
											fl = 1;
											p2 = p;
											bracketpos.push_back(p1);
											bracketpos.push_back(p2);
											p1 = 0;
											p2 = 0;
											break;
										}
									}
									p++;
								}
								if (fl == 0) {
									bracketpos.push_back(0);
									bracketpos.push_back(0);
								}
								p1 = 0;
								p2 = 0;
								break;
							}
						}
					}
				}			
			}
			else
			{
				cout << "\nНет круглой скобки в цикле" << endl;
			}
		}
		else {
			if ((q == "while") && (doflag == 0)) {
				doflag = 1;
			}
			if (q == "do") {
				int tempp1 = i;
				for (tempp1; tempp1 < wordcount; tempp1++) {
					if (words[tempp1 + 1] != "{") {
						int idk = tempp1 + 1;
						int ultraflag = 0;
						while (idk < wordcount) {
							if ((words[idk] == "\n")) {
								idk++;
								continue;
							}
							
							if ((words[idk] == "break") || (words[idk] == "continue")) {
								int u = idk+1;
								while (u < wordcount) {
									if (words[u + 1] == "\n") {
										u++;
										continue;
									}
									else {
										if (words[u + 1] == "while") {
											if (words[u + 2] == "(") {
												int tempp2 = u + 3;
												for (tempp2; tempp2 < wordcount; tempp2++) {
													if (words[tempp2] == "(") { //
														addbr1++;
													}
													if (words[tempp2] == ")") {
														if (addbr1 != 0) {
															addbr1--;
														}
														else {
															if (words[tempp2 + 1] == ";") {
																fl = 1;
																p2 = u;
																bracketpos.push_back(p1);
																bracketpos.push_back(p2);
																p1 = 0;
																p2 = 0;
																doflag = 0;
																ultraflag = 1;
																break;
															}
															else
																
															break;
														}
													}
												}
											}
										}
										else
											break;
										u++;
									}
									if (ultraflag)
										break;
								}
								
							}
							if (ultraflag)
								break;
							idk++;
						}
					}
					else {
						int p1 = tempp1 + 1, p = tempp1 + 2;
						int ultraflag = 0;
						while (p < wordcount) {
							if (words[p] == "{") {
								addbr2++;
							}
							if (words[p] == "}") {
								if (addbr2 != 0) {
									addbr2--;
								}
								else {
									int u = p;
									while (u < wordcount) {
										if (words[u + 1] == "\n") {
											u++;
											continue;
										}
										else {
											if (words[u + 1] == "while") {
												if (words[u + 2] == "(") {
													int tempp2 = u + 3;
													for (tempp2; tempp2 < wordcount; tempp2++) {
														if (words[tempp2] == "(") { //
															addbr1++;
														}
														if (words[tempp2] == ")") {
															if (addbr1 != 0) {
																addbr1--;
															}
															else {
																if (words[tempp2 + 1] == ";") {
																	fl = 1;
																	p2 = u;
																	bracketpos.push_back(p1);
																	bracketpos.push_back(p2);
																	p1 = 0;
																	p2 = 0;
																	doflag = 0;
																	ultraflag = 1;
																	break;
																}
																else
																	break;
															}
														}
													}
												}
											}
											else
												break;
											u++;	
										}
										if (ultraflag)
											break;
									}
								}

							}
							if (ultraflag)
								break;
							p++;	
						}
						if (fl == 0) {
							bracketpos.push_back(0);
							bracketpos.push_back(0);
						}
						p1 = 0;
						p2 = 0;
						break;
					}
				}
			}
		}
		i++;
	}
	for (int i = 0; i < wordcount; i++) {
		int lastlastflag = 0;
		if (words[i] == "\n")
			lines++;
		if ((words[i] == "continue")||(words[i] == "break")) {
			for (int j = 0; j < bracketpos.size(); j = j + 2) {
				if ((i >= bracketpos[j]) && (i <= bracketpos[j + 1])) {
					lastlastflag = 1;
				}
			}
			if (!lastlastflag) {
				if (words[i] == "continue")
					cout << "\n В строке " << lines << " Continue расположен неправильно!" << endl;
				else
					cout << "\n В строке " << lines << " Break расположен неправильно!" << endl;
			}
		}
	}
	
}
/*
void Processing::maincheck() {
	string nextline = "\n";
	int lines = 1;
	int i = 0;
	int c = 0;
	int pos = 0;
	for (string k : words) {
		if (k == "main") {
			for (string l : variablenames) {
				if (words[i-1] == l) {
					c++;
				}
			}
		}
		i++;
	}
	switch (c)
	{
		case(0):
			cout << "Отсутсвует main!";
			break;
		case(1):
			break;
		default:
			cout << "Функция main не может быть перегружена!";
			break;
	}
}
*/
void Processing::inicheck() {
	for (int i = 0; i < wordcount; i++) {
		int lines = 1;
		int l = 0;//для кейса

		if (words[i] == "\n") {
			lines++;
			break;
		}
		if (words[i] == "int") {
			if (words[i + 1] == "main")
				continue;
			for (string k : namesint) {
				if ((words[i + 1]) == k) {
					cout << "\nВ строке " << lines << "неправильно инициализированна(-ы) переменная(-е)!" << endl;
					break;
				}
			}
			int symbolcheck = 1;
			if (!isalpha(words[i + 1][0])) {
					symbolcheck = 0;
			}
			if (symbolcheck) {
				namesint.push_back(words[i + 1]);
			}
			else {
				cout << "\nВ строке " << lines << " недопустимое название переменной!" << endl;
				break;
			}
			int j = i+1;
			int strl = 0;
			while ((words[j] != "\n")&&!(strl == wordcount)) {
				if (words[j] == ",") {
					if (words[j + 1] != "int") {
						for (string k : namesint) {
							if ((words[j + 1]) == k) {
								cout << "\nВ строке " << lines << "неправильно инициализированна(-ы) переменная(-е)!" << endl;
								break;
							}
						}
						int symbolcheck = 1;
						if (!isalpha(words[j + 1][0])) {
							symbolcheck = 0;
						}
						if (symbolcheck) {
							namesint.push_back(words[j + 1]);
						}
						else {
							cout << "\nВ строке " << lines << " недопустимое название переменной!" << endl;
							break;
						}
						if (words[j + 2] == "=") {
							;
						}
					}
					else {
						cout << "\nВ строке " << lines << "неправильно инициализированна(-ы) переменная(-е)!" << endl;
						break;
					}
				}
				else {
					int y = j;
					bool jb = 0;//флаг
					int prada = 1;
					if (words[y] == "=") {
						while ((words[y]!= "\n")&&!(strl == wordcount))
						{
							if ((words[y] == "(") || (words[y] == ")")) {
								y++;
								continue;
							}
							for (string el : namesint) {
								if (words[y] == el) {
									jb = 1;
									continue;
								}
							}
							for (int q = 0; q < words[i].size(); q++) {
								if (!isalpha(words[i][q])) {
									prada = 0;
									break;
								}
							}

						}
					}
					if (!prada) {
						cout << "\nБез инвайта";
					}
				}
				j++;
				strl++;
			}
			i = j;
			lines++;
		}
		int flag = 0;
		if (words[i] == "=") {
			for (string k : namesint) {
				if ((words[i - 1]) == k) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "\nВ строке " << lines << " неправильно инициализированна(-ы) переменная(-е)!" << endl;
			}
		}
	}
}
