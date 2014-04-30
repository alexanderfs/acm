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

int n;
int pokerlist[20];

void myquicksort(int a, int b) {
	if(b - a < 1) {
		return;
	}
	int flagval = pokerlist[b];
	int ia = a;
	for(int i = a; i < b; i++) if(pokerlist[i] < flagval) {
		int tmp = pokerlist[i];
		pokerlist[i] = pokerlist[ia];
		pokerlist[ia] = tmp;
		ia++;
	}
	pokerlist[b] = pokerlist[ia];
	pokerlist[ia] = flagval;
	myquicksort(a, ia - 1);
	myquicksort(ia + 1, b);
}

int calzero() {
	int zn = 0;
	int i = 0;
	while(pokerlist[i] == 0) {
		i++;
		zn++;
	}
	return zn;
}

int calgap(int start) {
	int gn = 0;
	for(int i = start + 1; i < n; i++) {
		int dis = pokerlist[i] - pokerlist[i - 1];
		if(dis == 0) {
			return -1;
		}
		gn += (dis - 1);
	}
	return gn;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		if(n == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &pokerlist[i]);
		}
		myquicksort(0, n - 1);
		int zerocount = calzero();
		int gapcount = calgap(zerocount);
		if(n != -1 && zerocount >= gapcount) {
			printf("So Lucky!\n");
		} else {
			printf("Oh My God!\n");
		}
	} 

	return 0;
}