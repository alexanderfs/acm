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

int t;
int bt[2];
int f[10005];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while (cin >> bt[0] >> bt[1] >> t) {
		memset(f, -1, sizeof(int) * (t + 1));
		f[0] = 0 ;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= t; j++) if (j >= bt[i]){
				if (f[j - bt[i]] != -1 && f[j] < f[j - bt[i]] + 1) {
					f[j] = f[j - bt[i]] + 1;
				}
			}
		}
	
		if (f[t] != -1) {
			cout << f[t] << endl;
		}
		else {
			int t1 = t;
			while (f[--t1] == -1) {
				;
			}
			cout << f[t1] << " " << t - t1 << endl;
		}
		
	}

	return 0;
}