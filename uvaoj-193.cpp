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
int graph[101][101];
int bcount;
int bmax;
int blist[101];
int bmaxlist[101];
int n;

int countBlack()
{
	int val = 0;
	for(int i = 0; i <= n; i++) {
		if(blist[i] == 1) {
			val++;
		}
	}
	return val;
}

bool checkValid(int len, int c)
{
	for(int i = 1; i <= len; i++) {
		if(graph[i][len] && blist[i] == c) {
			return false;
		}
	}
	return true;
}

void dfs(int curr)
{
	if(curr == n + 1) {
		bcount = countBlack();
		if(bcount > bmax) {
			bmax = bcount;
			memcpy(bmaxlist, blist, sizeof(blist));
		}
		return;
	}
	
	if(checkValid(curr, 1)) {
		blist[curr] = 1;
		dfs(curr + 1);
		blist[curr] = 0;
	}
	//if(checkValid(curr, 0)) {
		blist[curr] = 0;
		dfs(curr + 1);
	//} 
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int gcount;
	int k;
	cin >> gcount;
	while(gcount--) {
		cin >> n >> k;
		int a, b;
		memset(graph, 0, sizeof(graph));
		bmax = 0;
		for(int i = 0; i < k; i++) {
			cin >> a >> b;
			graph[a][b] = graph[b][a] = 1;
		}
		dfs(1);
		
		cout << bmax << endl;
		for(int i = 1, j = 1; i <= n; i++) {
			if(bmaxlist[i] == 1) {
				cout << i;
				if(j < bmax) {
					cout << " ";
				}
				j++;
			}
		}
		cout << endl;
		
		bmax = 0;
		memset(blist, 0, sizeof(blist));
	}
	return 0;
}