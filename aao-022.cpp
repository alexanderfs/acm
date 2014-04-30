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

int numList[100005];
int numStack[100005];
int n;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numList[i]);
		}
		int idx = 0;
		int nidx = 0;
		int ntop = 0;
		int tmp;
		bool isValid = true;
		numStack[ntop++] = numList[idx++];
		while(nidx < n) {
			scanf("%d", &tmp);
			nidx++;
			while(numStack[ntop - 1] != tmp) {
				if(idx == n) {
					isValid = false;
					break;
				}
				numStack[ntop++] = numList[idx++];
			}
			if(isValid) {
				ntop--;
			} else {
				while(nidx < n) {
					scanf("%d", &tmp);
					nidx++;
				}
				break;
			}
		}
		if(isValid) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}