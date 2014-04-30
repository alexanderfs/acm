/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 很二的问题。 第32行找第一个是1的位。再多看几遍好好想想吧。 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int numlist[1000005];
int n;
int val;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		val = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist[i]);
			val ^= numlist[i];
		}
		int mymask = 1;
		for(int i = 0; i < 32; i++) {
			if((val & (1 << i)) != 0) {
				mymask = 1 << i;
				break;
			}
		}
		int val1 = 0;
		int val2 = 0;
		for(int i = 0; i < n; i++) {
			if((numlist[i] & mymask) != 0) {
				val1 ^= numlist[i];
			} else {
				val2 ^= numlist[i];
			}
		}
		
		if(val1 > val2) {
			val1 = val1 ^ val2;
			val2 = val1 ^ val2;
			val1 = val1 ^ val2;
		}
		printf("%d %d\n", val1, val2);
	}

	return 0;
}