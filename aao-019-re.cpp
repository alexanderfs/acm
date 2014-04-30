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
#include <cstring>
using namespace std;

int nodeList[1005];
int lcList[1005];
int rcList[1005];
int noden;

int pCount = 0;

void dfs(void) {
	int curr = 1;
	int prev = -1;
	int pcount = 0;
	while(curr != -1) {
		if(rcList[curr] == -1) {
			if(pcount == 0) {
				printf("%d", nodeList[curr]);
			} else {
				printf(" %d", nodeList[curr]);
			}
			pcount++;
			curr = lcList[curr];
		} else {
			prev = rcList[curr];
			while(lcList[prev] != -1 && lcList[prev] != curr) {
				prev = lcList[prev];
			}
			if(lcList[prev] == -1) {
				if(pcount == 0) {
					printf("%d", nodeList[curr]);
				} else {
					printf(" %d", nodeList[curr]);
				}
				pcount++;
				lcList[prev] = curr;
				curr = rcList[curr];
			} else {
				lcList[prev] = -1;
				curr = lcList[curr];
			}
		}
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &noden)) {
		if(noden == 0) {
			printf("NULL\n");
		}
		for(int i = 1; i <= noden; i++) {
			scanf("%d", &nodeList[i]);
		}
		char idc;
		
		for(int i = 1; i <= noden; i++) {
			getchar();
			scanf("%c", &idc);
			switch(idc) {
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
					lcList[i] = -1;
					rcList[i] = -1;
					break;
				default:
					lcList[i] = -1;
					rcList[i] = -1;
					break;
			}
		}
		pCount
		dfs(1);
	}

	return 0;
}