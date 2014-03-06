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
#include <cstring>
using namespace std;

int m;
int cList[100];
int sum;
int f[50000];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> m;
		if(m == 0) {
			cout << 0 << endl;
			continue;
		}
		sum = 0;
		for(int i = 0; i < m; i++) {
			cin >> cList[i];
			sum += cList[i];
		}
		int half = sum / 2;
		for(int i = 0; i < m; i++) {
			for(int j = half; j > 0; j--) {
				if(cList[i] <= j && cList[i] + f[j - cList[i]] > f[j]) {
					f[j] = cList[i] + f[j - cList[i]];
				}
			}
		}
		int dif = sum - f[half] - f[half];
		if(dif < 0) {
			dif = -dif;
		}
		cout << dif << endl;
		memset(f, 0, sizeof(int) * half);
	}

	return 0;
}