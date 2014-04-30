/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 一个时间优化的问题。不要每次都重新计算总和 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int sum;

int sumlist[60000];

void initsumlist() {
	for(int i = 1; i < 60000; i++) {
		sumlist[i] = i + sumlist[i - 1];
	}
}


int getSum(int start, int end) {
	if(end <= 60000) {
		return sumlist[end] - sumlist[start - 1];
	}
	int val = start;
	int sumtmp = 0;
	while(val <= end) {
		sumtmp += val;
		val++;
	}
	return sumtmp;
}

void printResult(int a, int b) {
	printf("%d", a);
	for(int i = a + 1; i <= b; i++) {
		printf(" %d", i);
	}
	printf("\n");
}

int main() {
	freopen("test_input.txt", "r", stdin);
	//initsumlist();
	while(1 == scanf("%d", &sum)) {
		if(sum < 0) {
			break;
		}
		int a = 1;
		int b = 2;
		int recount = 0;
		int currsum = a + b;
		while(a < b) {
			if(currsum < sum) {
				b++;
				currsum += b;
			} else if(currsum > sum) {
				currsum -= a;
				a++;
			} else if(currsum == sum) {
				recount++;
				printResult(a, b);
				b++;
				currsum += b;
			}
		}
		//printf("[%d %d]\n", a, b);
		if(recount == 0) {
			printf("Pity!\n");
		}
		printf("#\n");
	}

	return 0;
}
