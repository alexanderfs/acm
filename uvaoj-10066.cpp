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

int t1[105];
int t2[105];
int d[105][105];
bool v[105][105];
int n1, n2;
int dx[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};

int dp(int i, int j)
{
	if(i < 1 || j < 1) {
		return 0;
	}
	if(v[i][j]) {
		return d[i][j];
	}
	v[i][j] = true;
	
	for(int k = 0; k < 3; k++) {
		if(k == 0 && t1[i] == t2[j]) {
			int val = 1 + dp(i + dx[k][0], j + dx[k][1]);
			if(d[i][j] < val) {
				d[i][j] = val;
			}
		}
		int val = dp(i + dx[k][0], j + dx[k][1]);
		if(d[i][j] < val) {
			d[i][j] = val;
		}
	}
	
	return d[i][j];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 0;
	while(cin >> n1 >> n2) {
		if(!n1 && !n2) {
			break;
		}
		for(int i = 1; i <= n1; i++) {
			cin >> t1[i];
		}
		for(int i = 1; i <= n2; i++) {
			cin >> t2[i];
		}
		memset(d, 0, sizeof(d));
		memset(v, false, sizeof(v));
		cout << "Twin Towers #" << ++count << endl;
		cout << "Number of Tiles : " << dp(n1, n2) << endl << endl;
	}

	return 0;
}