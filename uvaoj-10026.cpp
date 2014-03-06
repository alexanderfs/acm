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
#include <fstream>
#include <algorithm>
using namespace std;

const int MAXLEN = 1005;

int n;
typedef int dpair[2];
dpair dataList[MAXLEN];
int seqList[MAXLEN];

bool isLess(int a, int b)
{
	return dataList[a][0] * dataList[b][1] < dataList[b][0] * dataList[a][1];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int cc;
	cin >> cc;
	while(cc--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> dataList[i][0] >> dataList[i][1];
			seqList[i] = i;
		}
		sort(seqList, seqList + n, isLess);
		cout << seqList[0] + 1;
		for(int i = 1; i < n; i++) {
			cout << " " << seqList[i] + 1;
		}
		cout << endl;
		if(cc > 0) {
			cout << endl;
		}
	}

	return 0;
}