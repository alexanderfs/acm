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

bool isList[1000000];

int main() {
	freopen("test_input.txt", "r", stdin);
	isList[1] = true;
	for(int i = 2; i < 1000000; i += 2) {
		isList[i] = true;
	}
	for(int i = 3; i < 1000000; i += 3) {
		isList[i] = true;
	}
	for(int i = 5; i < 1000000; i += 5) {
		isList[i] = true;
	}
	int n;
	while(1 == scanf("%d", &n)) {
		int count = 0;
		int i;
		for(i = 1; i < 1000000; i++) if(isList[i]) {
			count++;
			if(count == n) {
				break;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}