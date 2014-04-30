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
int n;

int lowbound(int val, int start, int end) {
	int mid;
	while(start < end) {
		mid = start + (end - start) / 2;
		if(numList[mid] >= val) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

int upbound(int val, int start, int end) {
	int mid;
	while(start < end) {
		mid = start + (end - start) / 2;
		if(numList[mid] <= val) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	return end;
}

int startList[100005];
int allList[100005];

void maxsum(int &sum, int &start, int &end) {
	startList[n - 1] = allList[n - 1] = numList[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		startList[i] = numList[i] > (numList[i] + startList[i + 1]) ? 
			numList[i] : (numList[i] + startList[i + 1]);
		allList[i] = startList[i] > allList[i + 1] ? startList[i] : allList[i + 1];
	}
	sum = allList[0];
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numList[i]);
		}
		int sum;
		int start, end;
		maxsum(sum, start, end);
		printf("%d %d %d\n", sum, start, end);
	}

	return 0;
}