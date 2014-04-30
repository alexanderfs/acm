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

using namespace std;

int nodeList[10005];
int lcList[10005];
int rcList[10005];
int n;
int val;
int currval;
int numStack[10005];
int ntop;

void dfs(int currnode, int currval, int ntop) {
	if(currval == val) {
		printf("A path is found:");
		for(int i = 0; i < ntop; i++) {
			printf(" %d", numStack[i]);
		}
		printf("\n");
	}
	if(lcList[currnode] != -1) {
		numStack[ntop] = lcList[currnode];
		dfs(lcList[currnode], currval + nodeList[lcList[currnode]], ntop + 1);	
	}
	if(rcList[currnode] != -1) {
		numStack[ntop] = rcList[currnode];
		dfs(rcList[currnode], currval + nodeList[rcList[currnode]], ntop + 1);
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(2 == scanf("%d %d", &n, &val)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &nodeList[i], &lcList[i], &rcList[i]);
		}
		printf("result:\n");
		currval = nodeList[1];
		ntop = 0;
		numStack[ntop++] = 1;
		dfs(1, currval, ntop);
	}
	
	return 0;
}