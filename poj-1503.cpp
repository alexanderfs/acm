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
#include <string>
using namespace std;

int veryBigInt[110];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string str;
	int maxlen = -1;
	while(cin >> str) {
		if(str.size() == 1 && str[0] == '0') {
			break;
		} else {
			int c = 0;
			int j = 0;
			for(int i = str.size() - 1; i >= 0; i--, j++) {
				int n = veryBigInt[j] + str[i] - '0' + c;
				c = n / 10;
				veryBigInt[j] = n % 10;
			}
			while(c) {
				int n = veryBigInt[j] + c;
				c = n / 10;
				veryBigInt[j++] = n % 10;
			}
			if(j > maxlen) {
				maxlen = j;
			}
		}
	}
	maxlen--;
	while(maxlen >= 0) {
		cout << veryBigInt[maxlen--];
	}
	cout << endl;

	return 0;
}