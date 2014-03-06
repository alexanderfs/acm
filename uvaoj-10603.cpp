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
#include <cmath>
using namespace std;

typedef int cstate[4];
cstate cq[1000000];
int visit[201][201][201];
int goal;
int maxa;
int d;
int blist[3];
int front, rear;
int head[10000];
int next[1000003];

void initLookupTable()
{
	memset(visit, 0, sizeof(visit));
}

int hash(cstate &s)
{
	int pro = 1;
	for(int i = 0; i < 3; i++) if(s[i] != 0){
		pro *= s[i];
	}
	pro %= 10000;
	return pro;
}

/*bool isExist(int idx)
{
	int h = hash(cq[idx]);
	int node = head[h];
	while(node) {
		if(memcmp(cq[idx], cq[node], sizeof(cq[idx])) == 0) {
			return true;
		}
		node = next[node];
	}
	next[idx] = head[h];
	head[h] = idx;
	return false;
}*/

bool isExist(int idx) 
{
	if(visit[cq[idx][0]][cq[idx][1]][cq[idx][2]]) {
		return true;
	} else {
		return false;
	}
}

void bfs()
{
	initLookupTable();
	while(front < rear) {
		
		cstate &first = cq[front++];
		//cout << first[3] << ", " << front << ", " << rear << endl;
		if((first[0] == goal || first[1] == goal || first[2] == goal) &&
			first[3] < maxa) {
			maxa = first[3];
		} else if(first[3] >= maxa) {
			continue;
		}
		for(int i = 0; i < 3; i++) {
			if(first[i] != 0) {
				for(int j = 0; j < 3; j++) if(j != i) {
					if((blist[j] - first[j]) >= first[i]) {
						cstate &end = cq[rear];
						memcpy(end, first, sizeof(first));
						end[3] += end[i];
						end[j] += end[i];
						end[i] = 0;
					} else {
						cstate &end = cq[rear];
						memcpy(end, first, sizeof(first));
						end[3] += (blist[j] - end[j]);
						end[i] -= (blist[j] - end[j]);
						end[j] = blist[j];
					}
					if(isExist(rear) == false) {
						visit[cq[rear][0]][cq[rear][1]][cq[rear][2]] = 1;
						rear++;
					}
				}
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		cin >> blist[0] >> blist[1] >> blist[2] >> d;
		for(int cd = d; cd > 0  ; cd--) {
			cstate &first = cq[0];
			first[0] = 0;
			first[1] = 0;
			first[2] = blist[2];
			first[3] = 0;
			front = 0;
			rear = 1;
			goal = cd;
			maxa = ~(1 << 31);
			bfs();
			if(maxa != ~(1 << 31)) {
				break;
			}
		}
		cout << maxa << " " << goal << endl;
	}

	return 0;
}