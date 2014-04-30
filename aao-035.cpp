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
#include <cstring>
#include <map>
using namespace std;

char aList[10005];
int aCount[26];
int seq;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%s", aList)) {
		memset(aCount, 0, sizeof(aCount));
		int i = 0;
		seq = 0;
		while(aList[i] != '\0') {
			int idx = aList[i] - 'A';
			if(aCount[idx] == 0) {
				aCount[idx] = --seq;
			} else if(aCount[idx] < 0) {
				aCount[idx] = 1;
			}
			i++;
		}
		int idx;
		for(idx = 0; idx < 26; idx++) if(aCount[idx] < 0) {
			break;
		}
		if(idx == 26) {
			printf("-1\n");
		} else {
			char target = 'A' + idx;
			int i = 0;
			while(aList[i] != target) {
				i++;
			}
			printf("%d\n", i);
		}
	}

	return 0;
}