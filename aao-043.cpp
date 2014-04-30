/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 动态规划问题 
 f(k, n) = f(k-1, n-1) + ...
 两种排序方法比较，实验看来快排还是可能改变原数组的顺序。插入排序不会。
 我就是用STL用到折翼的天使啊哈哈哈哈
 题目中的变态要求，四舍五入到两位小数后再排序 
 不知道哪里错了 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int f[10][100];
int idxlist[100];
double valuelist[100];

void myqsort(int start, int end) {
	if(end - start < 1) {
		return;
	}
	int a = start;
	int tmp = f[n][idxlist[end]];
	for(int i = start; i <= end - 1 ; i++) {
		if(f[n][idxlist[i]] > tmp) {
			idxlist[i] = idxlist[i] ^ idxlist[a];
			idxlist[a] = idxlist[i] ^ idxlist[a];
			idxlist[i] = idxlist[i] ^ idxlist[a];
			a++;
		}	
	}
	idxlist[end] = idxlist[a] ^ idxlist[end];
	idxlist[a] = idxlist[a] ^ idxlist[end];
	idxlist[end] = idxlist[a] ^ idxlist[end];
	
	myqsort(start, a - 1);
	myqsort(a + 1, end);
}

void myinsertsort(int start, int end) {
	for(int i = start + 1; i <= end; i++) {
		int j = i - 1;
		int tmp = idxlist[i];
		while(j >= 0 && valuelist[idxlist[j]] < valuelist[tmp]) {
			idxlist[j + 1] = idxlist[j];
			j--;
		}
		idxlist[j + 1] = tmp;
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	scanf("%d", &n);
	while(true) {
		if(n == 0) {
			break;
		}
		scanf("%d", &m);
		memset(f, 0, sizeof(f));
		memset(valuelist, 0.0, sizeof(valuelist));
		for(int i = 1; i <= m; i++) {
			f[1][i] = 1;
		}
		for(int i = 2; i <= n; i++) {
			int start = i;
			int end = i * m;
			for(int j = start; j <= end; j++) {
				for(int k = 1; k <= m; k++) if(j - k > 0) {
					f[i][j] += f[i - 1][j - k];
				}
			}
		} 
		int sum = 0;
		for(int i = n, j = 0; i <= m * n; i++, j++) {
			idxlist[j] = i;
			sum += f[n][i];
		}
		for(int i = n, j = 0; i <= m * n; i++, j++) {
			valuelist[i] = static_cast<double>(f[n][i]) / sum;
			valuelist[i] = static_cast<int>(valuelist[i] * 100 + 0.5) / 100.0;
		}
		//myqsort(0, (m * n - n));
		myinsertsort(0, m * n - n);
		for(int i = 0; i < 3; i++) {
			printf("%d %.2f\n", idxlist[i], valuelist[idxlist[i]]);
		}
		scanf("%d", &n);
		if(n != 0) {
			printf("\n");
		} else {
			break;
		}
	}

	return 0;
}