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
#include <cctype>
#include <string>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string expr;
	while(cin >> expr) {
		int start;
		int val;
		if(!isdigit(expr[0])) {
			val = 0;
			start = 0;
		} else {
			val = expr[0] - '0';
			start = 1;
		}
		while(start < expr.size()) {
			int op = expr[start];
			int opr = expr[start + 1] - '0';
			switch(op) {
				case '+': {
					val += opr;
					break;
				}
				case '-': {
					val -= opr;
					break;
				}
				case '*': {
					val *= opr;
					break;
				}
				case '/': {
					val /= opr;
					break;
				}
			}
			start += 2;
		}
		cout << val << endl;
	}

	return 0;
}