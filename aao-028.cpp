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

char cList[15];
char pList[15];
int len;

void myswap(int a, int b) {
	char tmp = cList[a];
	cList[a] = cList[b];
	cList[b] = tmp;
}

void myqsort(int p, int q) {
	if(q - p < 2) {
		return;
	}
	int x = cList[q - 1];
	int i = p;
	for(int j = p; j < q - 1; j++) if(cList[j] <= x) {
		myswap(i++, j);
	}
	myswap(i, q - 1);
	myqsort(p, i);
	myqsort(i + 1, q);
}

void mypermutation(int idx) {
	if(cList[idx] == '\0') {
		printf("%s\n", pList);
		return;
	}
	for(int i = 0; i < len; i++) if(i == 0 || cList[i] != cList[i - 1]) {
		int c1 = 0;
		for(int j = 0; j < len; j++) if(cList[i] == cList[j]) {
			c1++;
		}
		int c2 = 0;
		for(int j = 0; j < idx; j++) if(pList[j] == cList[i]) {
			c2++;
		}
		if(c2 < c1) {
			pList[idx] = cList[i];
			mypermutation(idx + 1);
		}
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%s", cList)) {
		len = strlen(cList);
		myqsort(0, len);
		//printf("%s\n", cList);
		mypermutation(0);
	}

	return 0;
}