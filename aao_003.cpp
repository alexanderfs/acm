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
#include <cstdio>

using namespace std;

int mat[1005][1005];
int m, n;

bool isExist(int val) {
	if(val < mat[0][0] || val > mat[m - 1][n - 1]) {
		return false;
	}
	int x = 0;
	int y = n - 1;
	while(x < m && y >= 0) {
		if(mat[x][y] == val) {
			return true;
		} else if(mat[x][y] < val) {
			x++;
		} else {
			y--;
		}
	}
	return false;
}

int main() {
	//ifstream in("test_input.txt");
	//cin.rdbuf(in.rdbuf());
	//freopen("test_input.txt", "r", stdin);
	
	int a, b, c;
	for(int i = 0; i < 5; i++) {
		int count = scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", count);
	}
	while(scanf("%d %d", &m, &n) == 2) {
		int t;
		scanf("%d", &t);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		if(isExist(t)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}