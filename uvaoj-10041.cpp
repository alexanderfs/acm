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
#include <cstring>
using namespace std;

int r;
int valList[505];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> r;
		for(int i = 0; i < r; i++) {
			cin >> valList[i];
		}
		sort(valList, valList + r);
		int midval = valList[r / 2];
		int sum = 0;
		for(int i = 0; i < r; i++) if(valList[i] != midval) {
			int tmp = midval - valList[i];
			if(tmp < 0) {
				tmp = -tmp;
			}
			sum += tmp;
		}
		cout << sum << endl;
	}

	return 0;
}