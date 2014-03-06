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
#include <algorithm>
using namespace std;

int k, n;
int boxList[35][15];
int g[35][35];
int d[35];
bool v[35];

bool isSmaller(int *a, int *b, int s)
{
	for(int i = 0; i < s; i++) {
		if(*a++ >= *b++) {
			return false;
		}
	}
	return true;
}

int f(int curr)
{
	if(v[curr]) {
		return d[curr];
	}
	v[curr] = true;
	int &a = d[curr];
	for(int i = 1; i <= k; i++) if(g[curr][i]) {
		int b = f(i) + 1;
		if(a < b) {
			a = b;
		}
	}
	return a;
}

void printResult(int idx)
{
	for(int i = 1; i <= k; i++) if(g[idx][i]) {
		if(d[idx] == 1 + d[i]) {
			cout << " " << i;
			printResult(i);
			return;
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> k >> n) {
		for(int i = 1; i <= k; i++) {
			for(int j = 0; j < n; j++) {
				cin >> boxList[i][j];
			}
			sort(boxList[i], boxList[i] + n);
		}
		memset(g, 0, sizeof(g));
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= k; j++) if(i != j){
				if(isSmaller(boxList[i], boxList[j], n)) {
					g[i][j] = 1;
				}
			}
		}
		memset(d, 0, sizeof(d));
		memset(v, false, sizeof(v));
		int max = f(1);
		int tmp;
		int idx = 1;
		for(int i = 2; i <= k; i++) {
			tmp = f(i);
			if(tmp > max) {
				max = tmp;
				idx = i;
			}
		}
		cout << max + 1 << endl;
		cout <<	idx;
		printResult(idx);
		cout << endl;
	}

	return 0;
}