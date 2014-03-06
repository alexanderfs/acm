/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ³¬Ê±¡£ÄãÃÃµÄ 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int numList[505];
int slashList[505];
int maxSList[505];
int m, k;
int maxmin = ~(1 << 31);

void divideList(int curr, int idx)
{
	if(curr == k) {
		int max = 0;
		for(int i = 0; i < k - 1; i++) {
			int start = slashList[i];
			int end = slashList[i + 1];
			int sum = 0;
			for(int j = start; j < end; j++) {
				sum += numList[j];
			}
			if(sum > max) {
				max = sum;	
			}
		}
		int sum = 0;
		for(int i = slashList[k - 1]; i < m; i++) {
			sum += numList[i];
		}
		if(sum > max) {
			max = sum;
		}
		if(max < maxmin) {
			maxmin = max;
			memcpy(maxSList, slashList, sizeof(int) * k);
		}
		return;
	}
	
	for(int i = idx; i < m - 1 - (k - 1 - curr); i++) {
		slashList[curr] = i;
		divideList(curr + 1, i + 1);
	}
}

void printResult()
{
	cout << numList[0];
	for(int i = 1; i < k; i++) {
		int start = maxSList[i - 1];
		if(start == 0) {
			start = 1;
		}
		int end = maxSList[i];
		for(int j = start; j < end; j++) {
			cout << " " << numList[j];
		}
		cout << " /";
	}
	for(int i = maxSList[k - 1]; i < m; i++) {
		cout << " " << numList[i];
	}
	cout << endl;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> m >> k;
		for(int i = 0; i < m; i++) {
			cin >> numList[i];
		}
		//int kc = 0;
		if(k == 1) {
			cout << numList[0];
			for(int i = 1; i < m; i++) {
				cout << " " << numList[i];
			}
			cout << endl;
			continue;
		} else if(k == m) {
			cout << numList[0];
			for(int i = 1; i < m; i++) {
				cout << " / " << numList[i];
			}
			cout << endl;
			continue;
		}
		slashList[0] = 0;
		divideList(1, 1);
		printResult();
	}

	return 0;
}