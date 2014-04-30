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

const int LISTLEN = 1005;
int treeA[LISTLEN];
int rcA[LISTLEN];
int lcA[LISTLEN];
int treeB[LISTLEN];
int rcB[LISTLEN];
int lcB[LISTLEN];
int n, m;

bool dfs(int ia, int ib) {
	if(ib == -1) {
		return true;
	}
	if(ia == -1 && ib != -1) {
		return false;
	}
	if(treeA[ia] == treeB[ib]) {
		bool result = dfs(lcA[ia], lcB[ib]);
		if(!result) {
			return false;
		} else {
			return dfs(rcA[ia], rcB[ib]);
		}
	} else {
		return false;
	}
}

bool checkSame(int idxa, int idxb) {
	if(idxa == -1) {
		return false;
	}
	bool result = dfs(idxa, idxb);
	if(!result) {
		result = checkSame(lcA[idxa], idxb);
	}
	if(!result) {
		result = checkSame(rcA[idxa], idxb);
	}
	return result;
	/*if(idxb == -1) {
		return true;
	} else if(idxa == -1 && idxb != -1) {
		return false;
	}
	if(treeA[idxa] != treeB[idxb]) {
		bool result = checkSame(idxa, 1);
		return result;
	} else {
		bool result = checkSame(lcA[idxa], lcB[idxb]) && checkSame(rcA[idxa], rcB[idxb]);
		return result;
	}*/
}

int main() {
	freopen("test_input.txt", "r", stdin);
	
	while(scanf("%d %d", &n, &m) == 2) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &treeA[i]);
			rcA[i] = lcA[i] = -1;
		}
		for(int i = 1; i <= n; i++) {
			int cc = 0;
			scanf("%d", &cc);
			if(cc == 2) {
				scanf("%d %d", &lcA[i], &rcA[i]);
			} else if(cc == 1) {
				scanf("%d", &lcA[i]);
			}
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d", &treeB[i]);
			rcB[i] = lcB[i] = -1;
		}
		for(int i = 1; i <= m; i++) {
			int cc = 0;
			scanf("%d", &cc);
			if(cc == 2) {
				scanf("%d %d", &lcB[i], &rcB[i]);
			} else if(cc == 1) {
				scanf("%d", &lcB[i]);
			}
		}
		if(checkSame(1, 1)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}