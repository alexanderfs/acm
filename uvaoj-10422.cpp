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

typedef char cb[30];
cb chessboard;
cb target = "111110111100 110000100000";
struct cbnode {
	cb currstate;
	int steps;
};
cbnode cbq[1000000];
int front, rear;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int stepcount;

int head[10000];
int next[1000000];

void initHashTable()
{
	memset(head, 0, sizeof(head));
}

int hash(int idx)
{
	int val = 0;
	for(int i = 0; i < 16; i++) if(cbq[idx].currstate[i] != ' '){
		val = (val << 1) + cbq[idx].currstate[i] - '0';
	}
	return val % 10000;
}

bool isExist(int idx)
{
	int val = hash(idx);
	int node = head[val];
	while(node) {
		if(strcmp(cbq[node].currstate, cbq[idx].currstate) == 0) {
			return true;
		}
		node = next[node];
	}
	next[idx] = head[val];
	head[val] = idx;
	return false;
}

bool bfs()
{
	front = 0;
	rear = 1;
	initHashTable();
	cbnode &first = cbq[0];
	memcpy(first.currstate, chessboard, sizeof(chessboard));
	first.steps = stepcount = 0;
	
	while(front < rear) {
		cbnode &first = cbq[front++];
		//cout << first.currstate << endl;
		if(strcmp(first.currstate, target) == 0 && first.steps <= 10) {
			stepcount = first.steps;
			return true;
		} else if(first.steps > 10) {
			continue;
		}
		int z = 0;
		for(int i = 0; i < 25; i++) {
			if(first.currstate[i] == ' ') {
				z = i;
				break;
			}
		}
		int cx = z / 5;
		int cy = z % 5;
		int nx, ny;
		for(int i = 0; i < 8; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
				int nz = nx * 5 + ny;
				cbnode &last = cbq[rear];
				memcpy(last.currstate, first.currstate, sizeof(first.currstate));
				last.steps = first.steps;
				//memcpy(last, first, sizeof(first));
				char tmp = last.currstate[nz];
				last.currstate[nz] = ' ';
				last.currstate[z] = tmp;
				last.steps++;
				if(isExist(rear) == false) {
					rear++;
				}	
			}
		}
		
	}
	return false;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	while(count--) {
		string str;
		for(int i = 0; i < 5; i++) {
			getline(cin, str);
			for(int j = 0; j < 5; j++) {
				chessboard[i * 5 + j] = str[j];
			}
		}
		chessboard[25] = '\0';
		
		if(bfs()) {
			cout << "Solvable in " << stepcount << " move(s)." << endl;
		} else {
			cout << "Unsolvable in less than 11 move(s)." << endl;
		}
	}
	return 0;
}