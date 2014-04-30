/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 到目前为止查出来的BUG包括找出来的数为下标相同的两个 
 数，这样是不对的。但是怎么避免这种情况，数组中恰好有两个相同的数 
 
 还是不知道哪里错了。。还是换书上的做法吧。。 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int k;
int numlist[1000005];

int a, b;
long long product;

int bisearch(int val) {
	int start = 0;
	int end = n;
	while(start < end) {
		int mid = (end - start) / 2 + start;
		if(numlist[mid] == val) {
			return mid;
		} if(numlist[mid] > val) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

int upbound(int val) {
	int start = 0;
	int end = n;
	while(start < end) {
		int mid = (end - start) / 2 + start;
		if(numlist[mid] <= val) {
			start  = mid + 1;
		} else {
			end = mid;
		}
	}
	return start;
}

int lowbound(int val) {
	int start = 0;
	int end = n;
	while(start < end) {
		int mid = (end - start) / 2 + start;
		if(numlist[mid] >= val) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(2 == scanf("%d %d", &n, &k)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist[i]);
		}
		product = ~((long long)1 << 63);
		int idx = lowbound(k);
		for(int i = 0; i < n; i++) {
			int val = k - numlist[i];
			int bi = bisearch(val);
			if(bi != -1) {
				if(i < bi && (numlist[i] != numlist[bi]) && numlist[i] * numlist[bi] < product) {
					product = numlist[i] * numlist[bi];
					a = numlist[i];
					b = numlist[bi];
				} else if(i == bi && upbound(numlist[i]) - lowbound(numlist[i]) > 1 && numlist[i] * numlist[bi] < product) {
					product = numlist[i] * numlist[bi];
					a = numlist[i];
					b = numlist[bi];
				}
			}
		}
		if(product == ~((long long)1 << 63)) {
			printf("-1 -1\n");
		} else {
			printf("%d %d\n", a, b);
		}
	}

	return 0;
}