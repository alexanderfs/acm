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

long long d[30005];
int m[5] = {1, 5, 10, 25, 50};

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	d[0] = 1;
	for(int i = 0; i < 5; i++) {
		for(int j = 1; j <= 30000; j++) if(j >= m[i]){
			d[j] += d[j - m[i]];
		}
	}
	int amount;
	while(cin >> amount) {
		if(d[amount] > 1) {
			cout << "There are " << d[amount] << " ways to produce " << amount << " cents change." << endl;
		} else {
			cout << "There is only 1 way to produce " << amount << " cents change." << endl;
		}
	}

	return 0;
}