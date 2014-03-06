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

typedef int Stat[9];
Stat sq[1000000];
Stat target;
int dist[1000000];
int head[1000000];
int next[1000000];
int front, rear;
int prev[1000000];
int maxCount;
int maxIdx;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int path[1000000];
char movecmd[5] = "UDLR";

void initLookupTable()
{
	memset(head, 0, sizeof(head));
}

int hash(int idx)
{
	int val = 0;
	for(int i = 0; i < 9; i++) {
		val = val * 10 + sq[idx][i];
	}
	return val % 1000000;
}

bool isExist(int idx)
{
	int val = hash(idx);
	int node = head[val];
	while(node) {
		if(memcmp(sq[idx], sq[node], sizeof(sq[node])) == 0) {
			return true;
		}
		node = next[node];
	}
	next[idx] = head[val];
	head[val] = idx;
	return false;
}

void bfs()
{
	initLookupTable();
	front = 0;
	rear = 1;
	Stat &first = sq[front];
	for(int i = 0; i < 9; i++) {
		cin >> first[i];
	}
	memset(dist, 0, sizeof(dist));
	dist[front] = 0;
	prev[front] = 0;
	while(front < rear) {
		Stat &first = sq[front];
		if(dist[front] >= maxCount) {
			maxCount = dist[front];
			maxIdx = front;
		}
		
		int x, y, z;
		for(int i = 0; i < 9; i++) {
			if(first[i] == 0) {
				z = i;
				break;
			}
		}
		x = z / 3;
		y = z % 3;
		int nx, ny, nz;
		for(int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				nz = nx * 3 + ny;
				Stat &last = sq[rear];
				memcpy(last, first, sizeof(first));
				last[nz] = first[z];
				last[z] = first[nz];
				if(isExist(rear) == false) {
					dist[rear] = dist[front] + 1;
					prev[rear] = front;
					rear++;
				}
			}
		}
		front++;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int casenum;
	cin >> casenum;
	for(int i = 1; i <= casenum; i++) {
		bfs();
		int j = 0;
		int pre = maxIdx;
		while(pre) {
			path[j++] = pre;
			pre = prev[pre];
		}
		path[j] = 0;
		cout << "Puzzle #" << i << endl;
		for(int k = 0; k < 9; k++) {
			cout << sq[maxIdx][k];
			if(k % 3 == 2) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
		
		int zp, nzp;
		for(int k = 0; k < 9; k++) {
			if(sq[path[j]][k] == 0) {
				zp = k;
				break;
			}
		}
		while(j > 0) {
			
			for(int k = 0; k < 4; k++) {
				nzp = 3 * (zp / 3 + dx[k]) + (zp % 3 + dy[k]);
				if(nzp >= 0 && sq[path[j - 1]][nzp] == 0) {
					cout << movecmd[k];
					break;
				}
			}
			j--;
			zp = nzp;
		}
		cout << endl << endl;
	}
	return 0;
}