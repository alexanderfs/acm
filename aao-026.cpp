/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt98.947368421053 
 *               
 * Description : 
 *               
 	
	   
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int numList1[1005];
int numList2[1005];
int n;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numList1[i]);
		}
		for(int j = 0; j < n; j++) {
			scanf("%d", &numList2[j]);
		}
		for(int i = 0; i < n; i++) {
			printf("%d %d\n", numList1[i], numList2[i]);
		}
	}

	return 0;
}