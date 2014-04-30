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

priority_queue<int, vector<int>, greater<int> > mq;
int n;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		
		for(int i = 0; i < n; i++) {
			getchar();
			char opt;
			scanf("%c", &opt);
			if(opt == 's') {
				int tmp;
				scanf("%d", &tmp);
				mq.push(tmp);
				printf("%d\n", mq.top());
			} else if(opt == 'o') {
				if(mq.size() > 0) {
					mq.pop();
					printf("%d\n", mq.top());
				} else {
					printf("NULL\n");
				}
			}
		}
		while(mq.empty() == false) {
			mq.pop();
		}
	}

	return 0;
}