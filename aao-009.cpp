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
	long long fa = 0;
	long long fb = 1;
	long long fv;
	int n;
	while(cin >> n) {
		if(n < 2) {
			cout << n << endl;
		} else {
			for(int i = 0; i < n; i++) {
				fv = fa + fb;
				fa = fb;
				fb = fv;
			}
			cout << fv << endl;
		}
		fa = 0;
		fb = 1;
	}

	return 0;
}