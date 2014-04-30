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

#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

int nodeList[1005];
int lcList[1005];
int rcList[1005];
int n;
int myqueue[1005];
int front, rear;

void bfs() {
	front = rear = 0;
	myqueue[rear++] = 1;
	while(front < rear) {
		int curr = myqueue[front];
		if(lcList[curr] != -1) {
			myqueue[rear++] = lcList[curr];
		}
		if(rcList[curr] != -1) {
			myqueue[rear++] = rcList[curr];
		}
		if(curr == 1) {
			printf("%d", nodeList[curr]);
		} else {
			printf(" %d", nodeList[curr]);
		}
		front++;
	}
	printf("\n");
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &nodeList[i]);
		}
		for(int i = 1; i <= n; i++) {
			char t;
			scanf("%c", &t);
			while(!islower(t)) {
				scanf("%c", &t);
			}
			
			switch(t) {
				case 'd':
					scanf("%d %d", &lcList[i], &rcList[i]);
					break;
				case 'l':
					scanf("%d", &lcList[i]);
					rcList[i] = -1;
					break;
				case 'r':
					scanf("%d", &rcList[i]);
					lcList[i] = -1;
					break;
				case 'z':
					lcList[i] = rcList[i] = -1;
				default:
					break;
			}
		}
		bfs();
	}
	return 0;
}