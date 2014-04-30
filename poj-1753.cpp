/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 用被注释掉的那种方法就会超时。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

typedef char CB[17];
const int MAXLEN = 100000;
CB cbList[MAXLEN];
int head[MAXLEN];
int next[MAXLEN];
int layer[MAXLEN];
CB initState;
int front = 0;
int rear = 0;
CB finalState1 = "wwwwwwwwwwwwwwww";
CB finalState2 = "bbbbbbbbbbbbbbbb";
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
bool v[MAXLEN];

int hashVal(int idx)
{
	int val = 0;
	for(int i = 0; i < 16; i++) {
		//cout << cbList[idx][i];
		val = val * 2 + (cbList[idx][i] == 'w');
	}
	return val;
}

/*如果成功则表示之前没有处理过此状态*/
/*bool tryToInsert(int idx)
{
	int val = hashVal(idx);
	int h = head[val];
	while(h) {
		if(memcmp(cbList[idx], cbList[h], sizeof(cbList[idx])) == 0) {
			return false;
		}
		h = next[h];
	}
	next[idx] = head[val];
	head[val] = idx;
	return true;
}*/

bool tryToInsert(int idx)
{
	int val = hashVal(idx);
	bool re = v[val];
	if(!re) {
		v[val] = true;
	}
	return re == false;
}

int bfs()
{
	if(memcmp(initState, finalState1, sizeof(initState)) == 0) {
		return 0;
	}
	if(memcmp(initState, finalState2, sizeof(initState)) == 0) {
		return 0;
	}
	memcpy(cbList[front], initState, sizeof(initState));
	tryToInsert(front);
	rear++;
	while(rear > front) {
		CB &first = cbList[front];
		
		for(int i = 0; i < 16; i++) {
			CB &last = cbList[rear];
			memcpy(last, first, sizeof(first));
			int cx = i / 4;
			int cy = i % 4;
			int nx, ny;
			for(int j = 0; j < 5; j++) {
				nx = cx + dx[j];
				ny = cy + dy[j];
				if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
					last[nx * 4 + ny] = (last[nx * 4 + ny] == 'w' ? 'b' : 'w');
				}
			}
			if(memcmp(last, finalState1, sizeof(last)) == 0 || 
				memcmp(last, finalState2, sizeof(last)) == 0) {
				return layer[front] + 1;	
			}
			if(tryToInsert(rear)) {
				layer[rear] = layer[front] + 1;
				rear++;
			}
		}
		front++;
	}
	return -1;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string str;
	for(int i = 0; i < 4; i++) {
		getline(cin, str);
		for(int j = 0; j < 4; j++) {
			initState[i * 4 + j] = str[j];
		}
	}
	int val = bfs();
	if(val < 0) {
		cout << "Impossible" << endl;
	} else {
		cout << val << endl;
	}
	return 0;
}