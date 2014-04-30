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
int numstack[100000];

int main() {
	freopen("test_input.txt", "r", stdin);
	int top = 0;
	int v;
	while(true) {
		scanf("%d", &v);
		if(v == -1) {
			break;
		}
		numstack[top++] = v;
	}
	while(top > 0) {
		printf("%d\n", numstack[--top]);
	}

	return 0;
}