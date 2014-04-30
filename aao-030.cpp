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
#include <queue>
using namespace std;


int n, k;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(2 == scanf("%d %d", &n, &k)) {
		priority_queue<int, vector<int>, greater<int> > pq;
		for(int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			pq.push(tmp);
		}
		printf("%d", pq.top());
		pq.pop();
		for(int i = 1; i < k; i++) {
			printf(" %d", pq.top());
			pq.pop();
		}
		printf("\n");	
	}
	
	return 0;
}