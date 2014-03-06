/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 第一次提交错误，可能原因有两个：一个是只有一个矩阵时
 没有括号，另外就是在打印函数里面每一层找到一个方案后需要直接退出 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int matList[12][2];
int n;
long long d[12][12];
bool v[12][12];

int dp(int start, int end)
{
	if(v[start][end]) {
		return d[start][end];
	}
	v[start][end] = true;
	if(end - start < 1) {
		return d[start][end] = 0;
	}
	d[start][end] = ~(1 << 31);
	for(int i = start; i <= end - 1; i++) {
		int val = dp(start, i) + dp(i + 1, end) + matList[start][0] * matList[end][1] * matList[i + 1][0];
		if(val < d[start][end]) {
			d[start][end] = val;
		}
	}
	return d[start][end];
}

void printResult(int start, int end)
{
	if(start == end) {
		cout << "A" << start;
		return;
	}
	cout << "(";
	for(int i = start; i <= end - 1; i++) {
		if(d[start][end] == d[start][i] + d[i + 1][end] + matList[start][0] * matList[end][1] * matList[i + 1][0]) {
			printResult(start, i);
			cout << " x ";
			printResult(i + 1, end);
			break;
		}
	}
	cout << ")";
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 0;
	while(cin >> n) {
		if(!n) {
			break;
		}
		for(int i = 1; i <= n; i++) {
			cin >> matList[i][0] >> matList[i][1];
		}
		if(n == 1) {
			cout << "Case " << ++count << ": (A1)" << endl;
			continue; 
		}
		memset(d, 0, sizeof(d));
		memset(v, false, sizeof(v));	
		dp(1, n);
		cout << "Case " << ++count << ": ";
		printResult(1, n);
		cout << endl;
	}

	return 0;
}