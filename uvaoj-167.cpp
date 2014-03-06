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

int chess[8][8];
int iList[8];
int maxVal;

bool checkValid(int c, int len)
{
	for(int i = 0; i < len; i++) {
		if(iList[i] + i == c + len || iList[i] - i == c - len) {
			return false;
		}
	}
	return true;
}

void dfs(int curr)
{
	if(curr == 8) {
		int sum = 0;
		for(int i = 0; i < 8; i++) {
			sum += chess[i][iList[i]];
		}
		if(sum > maxVal) {
			maxVal = sum;
		}
		return;
	}
	for(int i = 0; i < 8; i++) {
		bool isFound = false;
		for(int j = 0; j < curr; j++) {
			if(iList[j] == i) {
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			if(checkValid(i, curr)) {
				iList[curr] = i;
				dfs(curr + 1);
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				cin >> chess[i][j];
			}
		}
		dfs(0);
		cout.width(5);
		cout << maxVal << endl;
		maxVal = 0;
	}

	return 0;
}