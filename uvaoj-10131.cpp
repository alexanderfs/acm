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
int g[1005][1005];
int e[1005][2];
int d[1005];
int v[1005];
int n = 1;

int dp(int idx)
{
	if(v[idx]) {
		return d[idx];
	}
	v[idx] = true;
	for(int i = 1; i < n; i++) {
		if(g[idx][i]) {
			int nd = dp(i);
			if(d[idx] < nd) {
				d[idx] = nd;
			}
		}
	}
	return d[idx] += 1;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> e[n][0] >> e[n][1]) {
		n++;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(e[i][0] < e[j][0] && e[i][1] > e[j][1]) {
				g[i][j] = 1;
			}
		}
	}
	int max = -1;
	int midx;
	for(int i = 1; i < n; i++) {
		int val = dp(i);
		if(max < val) {
			max = val;
			midx = i;
		}
	}
	cout << max << endl;
	for(int i = 0; i < max; i++) {
		cout << midx << endl;
		for(int j = 1; j < n; j++) if(g[midx][j] && d[midx] == d[j] + 1) {
			midx = j;
			break;
		}
	}

	return 0;
}