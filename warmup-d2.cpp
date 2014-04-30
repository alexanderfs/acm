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

int inittable[105];
int vtable[105];
int patt[15];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n, k;
int len;
long long pcount;

void dfs(int curr)
{
	if(curr == k) {
		pcount++;
		return;
	}
	int cx = patt[curr - 1] / n;
	int cy = patt[curr - 1] % n;
	for(int i = 0; i < 4; i++) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if(nx >=0 && nx < m && ny >= 0 && ny < n && !vtable[nx * n + ny]) {
			patt[curr] = nx * n + ny;
			vtable[nx * n + ny] = 1;
			dfs(curr + 1);
			vtable[nx * n + ny] = 0;
		}
	}
}

void init()
{
	for(int i = 0; i < 105; i++) {
		inittable[i] = i;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	init();
	while(cin >> n >> m >> k) {
		memset(vtable, 0, sizeof(vtable));
		pcount = 0;
		len = m * n;
		for(int i = 0; i < len; i++) {
			patt[0] = i;
			vtable[i] = 1;
			dfs(1);
			vtable[i] = 0;
		}
		cout << pcount << endl;
	}

	return 0;
}