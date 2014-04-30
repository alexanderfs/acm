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

using namespace std;

const int MAXLEN = 1005;
int n;
int numList[MAXLEN];
int f[MAXLEN];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> numList[i];
		}
		int maxval = -1;
		for(int i = 0; i < n; i++) {
			if(i == 0) {
				f[i] = 0;
			} else if(i == 1) {
				f[i] = numList[i] == numList[i - 1] ? 1 : 0;
				if(f[i] > maxval) {
					maxval = f[i];
				}
			} else {
				f[i] = 0;
				if(numList[i] == numList[i - 1]) {
					f[i] = f[i - 1] + 1;
				}
				if(numList[i] == numList[i - 2] && f[i - 2] >= f[i]) {
					f[i] = f[i - 2] + 1;
				}
				if(f[i] > maxval) {
					maxval = f[i];
				}
			}
			
		}
		cout << maxval + 1 << endl;
	}

	return 0;
}