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
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int bn;
int blockList[100][3];
int g[100][100];
int d[100];
bool v[100];
int cx[3][3] = {{0, 1, 2}, {0, 2, 1}, {1, 2, 0}};

void buildGraph()
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = 0;
			if(blockList[i][0] > blockList[j][0] && blockList[i][1] > blockList[j][1]) {
				g[i][j] = 1;
			}
		}
	}
}

int dp(int x)
{
	if(v[x]) {
		return d[x];
	}
	v[x] = true;
	d[x] = blockList[x][2];
	for(int i = 0; i < n; i++) if(g[x][i]) {
		int val = dp(i) + blockList[x][2];
		if(val > d[x]) {
			d[x] = val;
		}
	}
	return d[x];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 0;
	while(cin >> bn) {
		if(!bn) {
			break;
		}
		n = 0;
		for(int i = 0; i < bn; i++) {
			int tmp[3];
			cin >> tmp[0] >> tmp[1] >> tmp[2];
			sort(tmp, tmp + 3);
			for(int j = 0; j < 3; j++) {
				blockList[n][0] = tmp[cx[j][0]];
				blockList[n][1] = tmp[cx[j][1]];
				blockList[n][2] = tmp[cx[j][2]];
				if(n > 0 && blockList[n][0] == blockList[n - 1][0] && blockList[n][1] == blockList[n - 1][1]) {
					continue;
				}
				n++;
			}
		}
		buildGraph();
		int maxheight = -1;
		for(int i = 0; i < n; i++) {
			int val = dp(i);
			if(val > maxheight) {
				maxheight = val;
			}
		}
		cout << "Case " << ++count << ": maximum height = " << maxheight << endl;
		memset(v, false, sizeof(v));
	}
	return 0;
}