/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ��Ȼ��������Ѿһ��ӡ��û�а��쵰������ ���Ҷ������±�
 �����ܶ�ļ�����Ѿ���ǲ��������쵰������ 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>

using namespace std;
typedef long long bigint;
int numList[505];
int slashList[505];
long long sum;
int m, k;

bool isValid(bigint val)
{
	int count = k - 1;
	int upper = m - 1;
	int lower = k - 1;
	int i = 0;
	while(count--) {
		bigint tmpsum = 0;
		while(upper >= lower) {
			tmpsum += numList[upper];
			if(tmpsum > val) {
				break;
			} else {
				upper--;
			}
		}
		slashList[i++] = upper + 1;
		lower--;
	}
	bigint tmpsum = 0;
	while(upper >= 0) {
		tmpsum += numList[upper--];
		if(tmpsum > val) {
			return false;
		}
	}
	if(tmpsum > val) {
		return false;
	} else {
		return true;
	}
}

void getDivision()
{
	bigint upper = sum;
	bigint lower = 1;
	bigint mid;
	while(upper > lower) {
		mid = lower + (upper - lower) / 2;
		if(isValid(mid)) {
			upper = mid - 1;
		} else {
			lower = mid + 1;
		}
	}
	while(!isValid(mid)) {
		mid++;
	}
}

void printResult()
{
	slashList[k - 1] = 0;
	cout << numList[0];
	for(int i = k - 2; i >= 0; i--) {
		int start = slashList[i + 1];
		if(start == 0) {
			start = 1;
		}
		int end = slashList[i];
		for(int j = start; j < end; j++) {
			cout << " " << numList[j];
		}
		cout << " /";
	}
	for(int i = slashList[0]; i < m; i++) {
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
		sum = numList[0];
		for(int i = 1; i < m; i++) {
			sum += numList[i];
		}
		getDivision();
		printResult();
	}

	return 0;
}