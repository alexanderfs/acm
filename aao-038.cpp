/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 这里用的map，提示会超出内存限制。做的时候怎么没想到
 用lowerbound/upperbound做呢。排序数组啊。 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
map<int, int> mm;
int n;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		mm.clear();
		for(int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			mm[tmp]++;
		}
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			int val;
			scanf("%d", &val);
			if(mm.count(val) == 0) {
				printf("0\n");
			} else {
				printf("%d\n", mm[val]);
			}
		}
	}

	return 0;
}