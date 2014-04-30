/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 终于尼玛过了。各种诡异的问题，第一种方法一直有一个测试用例
 过不了，不知道为啥。好吧，而且还有相加为定值的两个数，相差越大其积越小 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int n, k;
int numlist[1000005];

int main() {
	freopen("test_input.txt", "r", stdin);
	while(2 == scanf("%d %d", &n, &k)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist[i]);
		}
		int start = 0;
		int end = n - 1;
	
		int rea = -1;
		int reb = -1;
		while(start < end) {
			int sum = numlist[start] + numlist[end];
			if(sum < k) {
				start++;
			} else if(sum > k) {
				end--;
			} else {		
				rea = numlist[start];
				reb = numlist[end];
				break;
			}
		}
		printf("%d %d\n", rea, reb);
	}

	return 0;
}