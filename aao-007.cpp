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

int numstack1[100005];
int numstack2[100005];
int top1;
int top2;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int oc;
	cin >> oc;
	string opstr;
	while(oc--) {
		cin >> opstr;
		if(opstr == "POP") {
			if(top2 > 0) {
				cout << numstack2[--top2] << endl;
			} else if(top1 > 0){
				while(top1 > 0) {
					numstack2[top2++] = numstack1[--top1];
				}
				cout << numstack2[--top2] << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			int val;
			cin >> val;
			numstack1[top1++] = val;
		}
	}

	return 0;
}