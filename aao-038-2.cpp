/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ���ö��ֲ��������� �ܽ�һ�������߽纯����lowbound��
 ���ص�һ�γ��ֵ�λ�ã����û�ҵ��򷵻�Ӧ�ò����λ�á�upbound�Ƿ���
 ���һ�γ��ֵ�λ�õ���һ��λ�ã����û�ҵ�������Ӧ�ò����λ�á� 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int numlist[1000005]; 
int m, k;

//���ص�һ�γ��ֵ�λ�� 
int lowbound(int val) {
	int start = 0;
	int end = n;
	
	while(start < end) {
		int mid = start + (end - start) / 2;
		if(numlist[mid] >= val) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

//�������һ�γ���λ�õ���һ��λ��
int upbound(int val) {
	int start = 0;
	int end = n;
	while(start < end) {
		int mid = start + (end - start) / 2;
		if(numlist[mid] <= val) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	return start;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &numlist[i]);
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d", &k);
			int low = lowbound(k);
			int up = upbound(k);
			printf("%d\n", up - low);
		}
	}

	return 0;
}