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

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;
int n;
int numList[1000005];
int val[1000005];
int span[3][500005][2];
int len[3];

int main()
{
	//ifstream in("test_input.txt");
	//cin.rdbuf(in.rdbuf());
	freopen("test_input.txt", "r", stdin);
	int tcn;
	scanf("%d", &tcn);
	while(tcn--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &numList[i]);
		}
		if(n <= 1) {
			printf("%d\n", n);
			continue;
		}
		int flag = 0;
		int p = 0;
		int q = 0;
		memset(len, 0, sizeof(len));
		memset(val, 0, sizeof(int) * n);
		for(int i = 1; i < n; i++) {
			int dif = numList[i] - numList[i - 1];
			if(dif == 0) {
				if(flag == 2) {
					q++;
				} else {
					span[flag][len[flag]][0] = p;
					span[flag][len[flag]][1] = q;
					len[flag]++;
					p = i - 1;
					q = i;
					flag = 2;
				}
			} else if(dif > 0) {
				if(flag == 0) {
					q++;
				} else {
					span[flag][len[flag]][0] = p;
					span[flag][len[flag]][1] = q;
					len[flag]++;
					p = i - 1;
					q = i;
					flag = 0;
				}
			} else if(dif < 0) {
				if(flag == 1) {
					q++;
				} else {
					span[flag][len[flag]][0] = p;
					span[flag][len[flag]][1] = q;
					len[flag]++;
					p = i - 1;
					q = i;
					flag = 1;
				}
			}
		}
		span[flag][len[flag]][0] = p;
		span[flag][len[flag]][1] = q;
		len[flag]++;
		
		for(int i = 0; i < len[2]; i++) {
			for(int j = span[2][i][0]; j <= span[2][i][1]; j++) {
				val[j] = 1;
			}
		}
		for(int i = 0; i < len[0]; i++) {
			for(int j = span[0][i][0], k = 1; j <= span[0][i][1]; j++, k++) {
				val[j] = k;
			}
		}
		for(int i = 0; i < len[1]; i++) {
			for(int j = span[1][i][1], k = span[1][i][1] - span[1][i][0] + 1; j >= span[1][i][0]; j--, k--) {
				if(j == span[1][i][1] && val[j] > k) {
					continue;
				}
				val[j] = k;
			}
		}
		
		long long sum = 0;
		for(int i = 0; i < n; i++) {
			sum += val[i];
		}
		printf("%lld\n", sum);
	}

	return 0;
}
