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

int m, n;
int numlist1[1005];
int numlist2[1005];

int main() {
	freopen("test_input.txt", "r", stdin);
	while(2 == scanf("%d %d", &m, &n)) {
		for(int i = 0; i < m; i++) {
			scanf("%d", &numlist1[i]);
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist2[i]);
		}
		int p = 0;
		int q = 0;
		if(m > n) {
			while(m - p > n) {
				p++;
			}
		} else {
			while(n - q > m) {
				q++;
			}
		}
		while(p < m) {
			if(numlist1[p] == numlist2[q]) {
				break;
			}
			p++;
			q++;
		}
		if(p == m) {
			printf("My God\n");
		} else {
			printf("%d\n", numlist1[p]);
		}
	}

	return 0;
}