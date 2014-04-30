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

int numlist[100005];
int tmplist[100005];
int n;
int tot;

int calTot(int start, int end) {
	if(end - start < 2) {
		return 0;
	}
	int mid = start + (end - start) / 2;
	int sum = calTot(start, mid);
	sum += calTot(mid, end);
	int p = start, q = mid;
	int idx = start;
	while(p != mid || q != end) {
		if(q == end || p != mid && numlist[p] <= numlist[q]) {
			tmplist[idx++] = numlist[p++];
		} else {
			tmplist[idx++] = numlist[q++];
			sum += mid - p;
		}
	}
	for(int i = start; i < end; i++) {
		numlist[i] = tmplist[i];
	}
	return sum;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist[i]);
		}
		tot = calTot(0, n);
		printf("%d\n", tot);
	}

	return 0;
}