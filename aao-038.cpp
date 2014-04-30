/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : �����õ�map����ʾ�ᳬ���ڴ����ơ�����ʱ����ôû�뵽
 ��lowerbound/upperbound���ء��������鰡�� 
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