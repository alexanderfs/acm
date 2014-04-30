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

string expr;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	
	while(tcn--) {
		cin >> expr;
		int count = 0;
		int len = expr.size();
		bool re = true;
		for(int i = 0; i < len; i++) {
			if(expr[i] == '(') {
				count++;
			} else if(expr[i] == ')') {
				count--;
				if(count < 0) {
					re = false;
					break;
				}
			}
		}
		if(count == 0) {
			re = true;
		} else {
			re = false;
		}
		if(re) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

	return 0;
}