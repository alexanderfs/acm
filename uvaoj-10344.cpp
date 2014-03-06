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

int v[5];
bool result = false;

void calc(int n, int cv)
{
	if(n == 5) {
		if(cv == 23) {
			result = true;
		}
		return;
	}
	int tmp;
	for(int i = 0; i < 3 && !result; i++) {
		if(i == 0) {
			tmp = cv + v[n];
		} else if(i == 1) {
			tmp = cv - v[n];
		} else {
			tmp = cv * v[n];
		}
		calc(n + 1, tmp);
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4]) {
		if(v[0] == 0) {
			break;
		}
		sort(&v[0], &v[5]);
		do {
			calc(1, v[0]);
		} while(next_permutation(&v[0], &v[5]));
		
		if(result) {
			cout << "Possible" << endl;
		} else {
			cout << "Impossible" << endl;
		}
		result = false;
	}
	return 0;
}