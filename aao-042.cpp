/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 题目理解错了。原来有多少空格就输出多少空格 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

char charstack[40];
string strline;
int cstop;

int getnextchar(int curr) {
	while(curr >= 0 && isblank(strline[curr])) {
		curr--;
	}
	if(curr < 0) {
		return -1;
	} else {
		return curr;
	}
}

void printcurrent() {
	while(cstop--) {
		cout << charstack[cstop];
	}
}

int main() {
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	while(getline(cin, strline)) {
		int len = strline.size();
		int lastidx = len - 1;
		int wcount = 0;
		while(true) {
			lastidx = getnextchar(lastidx);
			if(lastidx == -1) {
				break;
			} else if(wcount != 0) {
				cout << " ";
			}
			cstop = 0;
			while(lastidx >= 0 && !isblank(strline[lastidx])) {
				charstack[cstop++] = strline[lastidx--];
			}
			printcurrent();
			wcount++;
		}
		cout << endl;
	}
	return 0;
}