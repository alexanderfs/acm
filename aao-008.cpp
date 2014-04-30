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

int main() {
	freopen("test_input.txt", "r", stdin);
	int n;
	int pre = -1;
	int val;
	while(1 == scanf("%d", &n)) {
		if(n == 1) {
			scanf("%d", &val);
			printf("%d\n", val);
		} else {
			bool isPrint = false;
			for(int i = 0; i < n; i++) {
				scanf("%d", &val);
				if(val < pre && !isPrint) {
					printf("%d\n", val);
					isPrint = true;
				}
				pre = val;
			}
			if(!isPrint) {
				printf("%d\n", val);
			}
		}
		pre = -1;
	}

	return 0;
}