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

char textList1[105][35];
int n1;
char textList2[105][35];
int n2;
int d[105][105];
bool v[105][105];
int dx[3][2] = {{-1, -1}, {0, -1}, {-1, 0}};
int spaceCount;

int dp(int i1, int i2)
{
	if(i1 == 0 || i2 == 0) {
		return 0;
	}
	if(v[i1][i2]) {
		return d[i1][i2];
	}
	v[i1][i2] = true;
	d[i1][i2] = 0;
	for(int i = 0; i < 3; i++) {
		if(i == 0 && !strcmp(textList1[i1], textList2[i2])) {
			d[i1][i2] = 1 + dp(i1 + dx[i][0], i2 + dx[i][1]);
			continue;
		}
		int val = dp(i1 + dx[i][0], i2 + dx[i][1]);
		if(d[i1][i2] < val) {
			d[i1][i2] = val;
		}
	}
	return d[i1][i2];
}

void printResult(int i1, int i2)
{
	if(i1 == 0 || i2 == 0) {
		return;
	}
	for(int i = 0; i < 3; i++) {
		if(i == 0 && !strcmp(textList1[i1], textList2[i2])) {
			printResult(i1 - 1, i2 - 1);
			cout << textList1[i1];
			spaceCount--;
			if(spaceCount == 0) {
				cout << endl;
			} else {
				cout << " ";
			}
			break;
		}
		if(d[i1][i2] == d[i1 + dx[i][0]][i2 + dx[i][1]]) {
			printResult(i1 + dx[i][0], i2 + dx[i][1]);
			break;
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(true) {
		n1 = 1;
		while(cin >> textList1[n1]) {
			if(textList1[n1][0] == '#') {
				break;
			}
			n1++;
		}
		n1--;
		if(!cin) {
			break;
		}
		n2 = 1;
		while(cin >> textList2[n2]) {
			if(textList2[n2][0] == '#') {
				break;
			}
			n2++;
		}
		n2--;
		dp(n1, n2);
		spaceCount = d[n1][n2];
		printResult(n1, n2);
		
		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));
	}

	return 0;
}