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

int n;
int numList[100005];
int tmpList[100005];

void myswap(int a, int b) {
	int tmp = numList[a];
	numList[a] = numList[b];
	numList[b] = tmp;
}

void myqsort(int p, int q) {
	if(q - p < 1) {
		return;
	}
	int i = p;
	int val = numList[q];
	for(int j = p; j < q; j++) if(numList[i] <= val) {
		myswap(j, i);
		i++;
	}
	myswap(i, q);
	myqsort(p, i - 1);
	myqsort(i + 1, q);
}

void mymergeSort(int start, int end) {
	if(end - start < 2) {
		return;
	}
	int mid = (end - start) / 2 + start;
	mymergeSort(start, mid);
	mymergeSort(mid, end);
	int p = start;
	int q = mid;
	int idx = start;
	while(p < mid || q < end) {
		if(q == end || p != mid && numList[p] < numList[q]) {
			tmpList[idx++] = numList[p++];
		} else {
			tmpList[idx++] = numList[q++];
		}
	}
	for(int i = start; i < end; i++) {
		numList[i] = tmpList[i];
	}
}

int countNum() {
	int max = -1;
	int maxv;
	int count = 1;
	int curr = numList[0];
	for(int i = 1; i < n; i++) {
		if(numList[i] == curr) {
			count++;
		} else {
			if(max < count) {
				max = count;
				maxv = curr;
			}
			curr = numList[i];
			count = 1;
		}
	}
	if(max > n / 2) {
		return maxv;
	} else {
		return -1;
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numList[i]);
		}
		//mymergeSort(0, n);
		myqsort(0, n - 1);
		printf("%d\n", countNum());
	}

	return 0;
}