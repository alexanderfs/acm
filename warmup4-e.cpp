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
#include <cstdio>
using namespace std;

int sumList[500005];
int pileNum;

int main()
{
	//ifstream in("test_input.txt");
	//cin.rdbuf(in.rdbuf());
	freopen("test_input.txt", "r", stdin);
	int tcn;
	scanf("%d", &tcn);
	while(tcn--) {
		scanf("%d", &pileNum);
		int tmp = 0;
		int sum = 0;
		for(int i = 1; i <= pileNum; i++) {
			scanf("%d", &tmp);
			sum += tmp;
			sumList[i] = sum;
		}
		int qn;
		scanf("%d", &qn);
		int start, end;
		while(qn--) {
			scanf("%d %d", &start, &end);
			//cout << sumList[end] - sumList[start - 1] << endl;
			printf("%d\n", sumList[end] - sumList[start - 1]);
		}
	}

	return 0;
}