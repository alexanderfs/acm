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

int numList[10005];
int n;

bool checkValid(int start, int end) {
	if(end - start <= 1) {
		return true;
	}
	int rootval = numList[end - 1];
	int mid = start;
	while(mid < end - 1 && numList[mid] < rootval) {
		mid++;
	}
	if(mid == end - 1) {
		return checkValid(start, end - 1);
	}
	int tm = mid;
	while(tm < end - 1 && numList[tm] > rootval) {
		tm++;
	}
	if(tm == end - 1) {
		if(checkValid(start, mid) && checkValid(mid, end - 1)) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numList[i]);
		}
		if(checkValid(0, n)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}