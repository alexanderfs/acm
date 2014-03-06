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
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int r, c;
int g[105][105];
int d[105][105];
int v[105][105];

int dp(int ix, int iy)
{
	if(v[ix][iy]) {
		return d[ix][iy];
	}
	v[ix][iy] = true;
	d[ix][iy] = 0;
	for(int i = 0; i < 4; i++) {
		int nx = ix + dx[i];
		int ny = iy + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[ix][iy] > g[nx][ny]) {
			int val = 1 + dp(nx, ny);
			if(val > d[ix][iy]) {
				d[ix][iy] = val;
			}
		}
	}
	return d[ix][iy];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	string name;
	cin >> tcn;
	while(tcn--) {
		cin >> name;
		cin >> r >> c;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				cin >> g[i][j];
			}
		}
		int max = -1;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				int val = dp(i, j);
				if(max < val) {
					max = val;
				}
			}
		}
		cout << name << ": " << max + 1 << endl;
		memset(v, 0, sizeof(v));
	}

	return 0;
}