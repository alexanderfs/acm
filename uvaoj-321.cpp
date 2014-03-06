/*******************************************************************
* Copyright (C) Alex AN
*
* File Name   :
* Author      : Alex AN
* Create      :
* Mail        : alexbupt@gmail.com
* Blog        : http://blog.csdn.net/alexbupt
*
* Description :真尼玛无语了，简单的题目看来往往还是在细节上面决定最终的结果。
我应该就是没有考虑只有一个房间的情况。 
*
******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int r, d, s;
int dgraph[11][11];
int sgraph[11][11];
typedef int State[11];
State sq[100000];
State finalState;
int sqprev[100000];
int prevstack[100000];
int front, rear;

int head[100000];
int hnext[100000];

int myhash(int idx)
{
	int val = 0;
	for (int i = 0; i < 9; i++) {
		val = val * 10 + sq[idx][i];
	}
	return val % 100000;
}

bool isExist(int idx)
{
	int hv = myhash(idx);
	int n = head[hv];
	while (n) {
		if (memcmp(sq[idx], sq[n], sizeof(sq[idx])) == 0) {
			return true;
		}
		n = hnext[n];
	}
	hnext[idx] = head[hv];
	head[hv] = idx;
	return false;
}

bool bfs()
{
	memset(head, 0, sizeof(head));
	memset(sqprev, 0, sizeof(sqprev));
	memset(prevstack, 0, sizeof(prevstack));
	front = rear = 0;
	State &first = sq[front];
	memset(first, 0, sizeof(first));
	first[1] = 1;
	first[0] = 1;
	memset(finalState, 0, sizeof(finalState));
	finalState[r] = 1;
	finalState[0] = r;
	if(memcmp(first, finalState, sizeof(finalState)) == 0) {
		return true;
	}
	rear++;
	while (front < rear) {
		State &first = sq[front];
		int curPos = first[0];
		for (int i = 1; i < 11; i++) {
			if (dgraph[curPos][i] && first[i]) {
				State &last = sq[rear];
				memcpy(last, first, sizeof(first));
				last[0] = i;
				if (isExist(rear) == false) {
					sqprev[rear] = front;
					if (memcmp(last, finalState, sizeof(finalState)) == 0) {
						return true;
					}
					if(rear < 99999) {
						rear++;
					}
				}
			}
		}
		for (int i = 1; i < 11; i++) {
			if (sgraph[curPos][i] && i != curPos) {
				State &last = sq[rear];
				memcpy(last, first, sizeof(first));
				if (last[i] == 1) {
					last[i] = 0;
				}
				else {
					last[i] = 1;
				}
				if (isExist(rear) == false) {
					sqprev[rear] = front;
					if (memcmp(last, finalState, sizeof(finalState)) == 0) {
						return true;
					}
					if(rear < 99999) {
						rear++;
					}
				}
			}
		}
		
		front++;
	}
	
	return false;
}

void printResult()
{
	int st = 0;
	int idx = rear;
	while (idx) {
		prevstack[st++] = idx;
		idx = sqprev[idx];
	}
	prevstack[st] = 0;
	int pst = st;
	st--;
	int a, b;
	cout << "The problem can be solved in " << pst << " steps:" << endl;
	while (st >= 0) {
		a = prevstack[st];
		b = prevstack[pst];
		for (int i = 0; i < 11; i++) {
			if (sq[b][i] != sq[a][i]) {
				if (i == 0) {
					cout << "- Move to room " << sq[a][i] << "." << endl;
				}
				else {
					if (sq[a][i] == 0) {
						cout << "- Switch off light in room " << i << "." << endl;
					}
					else {
						cout << "- Switch on light in room " << i << "." << endl;
					}
				}
			}
		}
		pst = st;
		st--;
	}

}

void cleanJob()
{
	memset(dgraph, 0, sizeof(dgraph));
	memset(sgraph, 0, sizeof(sgraph));
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	ofstream out("test_output.txt");
	cout.rdbuf(out.rdbuf());
	int count = 0;
	while (cin >> r >> d >> s) {
		if (!r && !d && !s) {
			break;
		}
		int t1, t2;
		for (int i = 0; i < d; i++) {
			cin >> t1 >> t2;
			dgraph[t1][t2] = dgraph[t2][t1] = 1;
		}
		for (int i = 0; i < s; i++) {
			cin >> t1 >> t2;
			sgraph[t1][t2] = 1;
		}
		cout << "Villa #" << ++count << endl;
		if (bfs()) {
			printResult();
		}
		else {
			cout << "The problem cannot be solved." << endl;
		}
		cout << endl;
		cleanJob();
	}

	return 0;
}