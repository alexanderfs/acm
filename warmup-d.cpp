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

typedef char PATT[11];
PATT q[1000000];
int lenList[1000000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n;
int k;
int inittable[105];
long long front, rear;
int v;

void initp()
{
	v = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			inittable[i * m + j] = v++;
		}
	}
}

int bfs()
{
	PATT &first = q[first];
	lenList[front] = 0;
	rear++;
	while(front < rear) {
		PATT &first = q[f];
		int len = lenList[front];
		if(len == 0) {
			for(int i = 0; i < v; i++) {
				PATT &last = q[rear];
				memcpy(last, first, sizeof(first));
				
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n >> m >> k) {
		initp()
		bfs();
	}

	return 0;
}