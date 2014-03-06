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

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	int n;
	int minmax;
	int maxmax;
	cin >> tcn;
	while(tcn--) {
		cin >> n;
		int i;
		cin >> i;
		int a, d1, d2;
		minmax = maxmax = -1;
		while(i--) {
			cin >> a;
			d1 = a > (n - a) ? a : n - a;
			d2 = a > (n - a) ? n - a : a;
			if(d1 > maxmax) {
				maxmax = d1;
			}
			if(d2 > minmax) {
				minmax = d2;
			}
		}
		cout << minmax << " " << maxmax << endl;
	}

	return 0;
}