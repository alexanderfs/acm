/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int len;
int numList[1005];
int sortList[1005];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> len;
		for(int i = 0; i < len; i++) {
			cin >> numList[i];
			sortList[i] = numList[i];
		}
		if(len <= 2) {
			cout << "Alice Wins" << endl;
			continue;
		}
		sort(sortList, sortList + len);
		int counta = 0;
		int countd = 0;
		for(int i = 0; i < len; i++) if(sortList[i] != numList[i]) {
			counta++;
		}
		if(counta == 2 || counta == 0) {
			cout << "Alice Wins" << endl;
			continue;
		}
		for(int i = len - 1, j = 0; i >= 0; i--, j++) if(sortList[j] != numList[i]) {
			countd++;
		}
		if(countd == 2 || countd == 0) {
			cout << "Alice Wins" << endl;
			continue;
		}
		cout << "Tie" << endl;
	}

	return 0;
}