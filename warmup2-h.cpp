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
#include <vector>
using namespace std;

int numList[50005];
int f[50005];
int v[50005];
int n;
int maxlen;
vector<int> nodeList[50005];

void init()
{
	for (int i = 1; i < 25001; i++) {
		for (int j = i * 2; j < 50001; j+=i) {
			numList[j] += i;
		}
	}
	for(int i = 1; i < 50001; i++) {
		nodeList[i].push_back(numList[i]);
		nodeList[numList[i]].push_back(i);
	}
	/*for (int i = 1; i < 50001; i++) {
		int val = 0;
		int i2 = i >> 1;
		for (int j = 1; j <= i2; j++) {
			if (i % j == 0) {
				val += j;
			}
		}
		numList[i] = val;
	}*/
}

void dfs(int curr)
{
	int num = f[curr - 1];
	bool isFound = false;
	for(int i = 0; i < nodeList[num].size(); i++) {
		if(v[nodeList[num][i]] == 0 && nodeList[num][i] <= n) {
			v[nodeList[num][i]] = 1;
			f[curr] = v[nodeList[num][i]];
			dfs(curr + 1);
			v[nodeList[num][i]] = 0;
			isFound = true;
		}
	}
	/*
	for (int i = 1; i <= n; i++) if (!v[i]){
		if (val == i || num == numList[i]) {
			v[i] = 1;
			f[curr] = i;
			dfs(curr + 1);
			v[i] = 0;
			isFound = true;
		}
	}*/
	if (!isFound && curr > maxlen) {
		maxlen = curr;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	init();
	int tcn;
	cin >> tcn;
	while (tcn--) {
		cin >> n;
		f[0] = n;
		maxlen = -1;
		v[n] = 1;
		dfs(1);
		v[n] = 0;
		cout << maxlen - 1 << endl;
	}

	return 0;
}