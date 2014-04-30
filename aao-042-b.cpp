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

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

char strcontent[2005];
int len;
int k;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(cin >> strcontent >> k) {
		len = strlen(strcontent);
		for(int i = 0; i < len; i++) {
			strcontent[i + len] = strcontent[i];
		}
		strcontent[len + len] = '\0';
		int stopidx = k % len + len;
		for(int i = k % len; i < stopidx; i++) {
			cout << strcontent[i];
		}
		cout << endl;
	}
	return 0;
}