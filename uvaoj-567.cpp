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
#include <iomanip>
#include <cstring>
using namespace std;

int g[25][25];

void floyd()
{
	for(int k = 1; k <= 20; k++) {
		for(int i = 1; i <= 20; i++) {
			for(int j = 1; j <= 20; j++) if(g[i][j] > g[i][k] + g[k][j]){
				g[i][j] = g[i][k] + g[k][j];
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 0;
	while(true) {
		for(int i = 1; i <= 20; i++) {
			for(int j = 1; j <= 20; j++) {
				g[i][j] = 1000;
			}
		}
		for(int i = 1; i <= 19; i++) {
			int n;
			cin >> n;
			if(!cin) {
				return 0;
			}
			for(int j = 0; j < n; j++) {
				int v;
				cin >> v;
				g[i][v] = g[v][i] = 1;
			}
		}
		floyd();
		cout << "Test Set #" << ++count << endl;
		int qn;
		cin >> qn;
		int u, v;
		for(int i = 0; i < qn; i++) {
			cin >> u >> v;
			cout << setw(2) << u;
			cout << " to " << setw(2) << v << ": " << g[u][v] << endl;
		}
		cout << endl;
	}

	return 0;
}