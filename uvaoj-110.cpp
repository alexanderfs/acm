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

char valList[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

int num;

void printIFELSE(int n, int *cl, int offset)
{
	if(n == num) {
		for(int k = 0; k < offset; k++) {
			cout << " ";
		}
		cout << "writeln(";
		for(int i = 0; i < n; i++) {
			cout << valList[cl[i]];
			if(i != n - 1) {
				cout << ",";
			}
		}
		cout << ")" << endl;
		return;
	}
	int *curcp = new int[8];
	memcpy(curcp, cl, sizeof(int) * 8);
	curcp[n] = n;
	int curi = n;
	for(int k = 0; k < offset; k++) {
		cout << " ";
	}
	cout << "if " << valList[curcp[curi - 1]] << " < " << valList[curcp[curi]] << " then" << endl;
	printIFELSE(n + 1, curcp, offset + 2);
	do {
		int tmp = curcp[curi];
		curcp[curi] = curcp[curi - 1];
		curcp[curi - 1] = tmp;
		curi--;
		if(curi > 0) {
			for(int k = 0; k < offset; k++) {
				cout << " ";
			}
			cout << "else if " << valList[curcp[curi - 1]] << " < " << valList[curcp[curi]] << " then" << endl;
		} else {
			for(int k = 0; k < offset; k++) {
				cout << " ";
			}
			cout << "else" << endl;
		}
		printIFELSE(n + 1, curcp, offset + 2);
		
	} while (curi > 0);
	delete [] curcp;
}

void printPascal()
{
	cout << "program sort(input,output);" << endl;
	cout << "var" << endl;
	for(int i = 0; i < num; i++) {
		cout << valList[i];
		if(i < num - 1) {
			cout << ",";
		}
	}
	cout << " : integer;" << endl;
	cout << "begin" << endl;
	cout << "  readln(";
	for(int i = 0; i < num; i++) {
		cout << valList[i];
		if(i < num - 1) {
			cout << ",";
		}
	}
	cout << ");" << endl;
	int *curList = new int[8];
	curList[0] = 0;
	printIFELSE(1, curList, 2);
	cout << "end." << endl;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		cin >> num;
		printPascal();
		if(count != 0) {
			cout << endl;
		}
	}
	return 0;
}
