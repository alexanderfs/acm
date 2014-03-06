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

int mat[12][105];
int m, n;
int d[12][105];
int v[12][105];
int rdx[3][3] = {-1, 0, 1, 0, 1, -1, 1, -1, 0};

int dp(int row, int col)
{
	if(col > n) {
		return 0;
	}
	if(v[row][col]) {
		return d[row][col];
	}
	v[row][col] = true;
	d[row][col] = ~(1 << 31);
	for(int i = 0; i < 3; i++) {
		int nr = (row + rdx[0][i]) % m;
		if(nr < 1) {
			nr = m;
		}
		int nc = col + 1;
		int nv = dp(nr, nc);
		if(nv < d[row][col]) {
			d[row][col] = nv;
		}
	}
	
	return d[row][col] += mat[row][col];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> m >> n) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> mat[i][j];
			}
		}
		memset(d, 0, sizeof(d));
		memset(v, false, sizeof(v));
		for(int i = 1; i <= m; i++) {
			dp(i, 1);
		}
		int min = ~(1 << 31);
		int minidx;
		for(int i = 1; i <= m; i++) {
			if(min > d[i][1]) {
				min = d[i][1];
				minidx = i;
			}
		}
		cout << minidx;
		int dx;
		for(int i = 2; i <= n; i++) {
			if(minidx == 1) {
				dx = 1;
			} else if(minidx == m) {
				dx = 2;
			} else {
				dx = 0;
			}
			for(int j = 0; j < 3; j++) {
				int nr = (minidx + rdx[dx][j]) % m;
				if(nr == 0) {
					nr = m;
				}
				if(d[minidx][i - 1] - d[nr][i] == mat[minidx][i - 1]) {
					cout << " " << nr;
					minidx = nr;
					break;
				}
				
			}
		}
		cout << endl;
		cout << min << endl;
	}

	return 0;
}