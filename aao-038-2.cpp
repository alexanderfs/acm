/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 利用二分查找来做。 总结一下两个边界函数，lowbound是
 返回第一次出现的位置，如果没找到则返回应该插入的位置。upbound是返回
 最后一次出现的位置的下一个位置，如果没找到，返回应该插入的位置。 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int numlist[1000005]; 
int m, k;

//返回第一次出现的位置 
int lowbound(int val) {
	int start = 0;
	int end = n;
	
	while(start < end) {
		int mid = start + (end - start) / 2;
		if(numlist[mid] >= val) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

//返回最后一次出现位置的下一个位置
int upbound(int val) {
	int start = 0;
	int end = n;
	while(start < end) {
		int mid = start + (end - start) / 2;
		if(numlist[mid] <= val) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	return start;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist[i]);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d", &k);
			int low = lowbound(k);
			int up = upbound(k);
			printf("%d\n", up - low);
		}
	}

	return 0;
}