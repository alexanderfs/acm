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
#include <algorithm>
using namespace std;

int n, m, k;
char numList[35];

int main() {
	freopen("test_input.txt", "r", stdin);
	int tcn;
	scanf("%d", &tcn);
	while(tcn--) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 0; i < n; i++) {
			numList[i] = '0';
		}
		for(int i = 0; i < m; i++) {
			numList[n + i] = '1';
		}
		int count = 0;
		do {
			count++;
			if(count == k) {
				printf("%s\n", numList);
				break;
			}
		} while(next_permutation(numList, numList + m + n));
		
		if(count < k) {
			printf("Impossible\n");
		}
		memset(numList, 0, sizeof(numList));
	}
	
	return 0;
}