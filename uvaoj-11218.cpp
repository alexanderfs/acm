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
#include <cstring>
using namespace std;

typedef int Comb[4];
Comb comList[85];
int cList[3];
int aList[9]; //占用情况 
int n;
int maxs;

bool addComb(int idx)
{
	if(aList[comList[idx][0] - 1] == 0 &&
		aList[comList[idx][1] - 1] == 0 &&
		aList[comList[idx][2] - 1] == 0) {
		aList[comList[idx][0] - 1] = 1;
		aList[comList[idx][1] - 1] = 1;
		aList[comList[idx][2] - 1] = 1;
		return true;
	} else {
		return false;
	}
}

void subComb(int idx)
{
	aList[comList[idx][0] - 1] = 0;
	aList[comList[idx][1] - 1] = 0;
	aList[comList[idx][2] - 1] = 0;
}

void dfs(int curr)
{
	if(curr == 3) {
		int sum = comList[cList[0]][3] + comList[cList[1]][3] +
			comList[cList[2]][3];
		if(sum > maxs) {
			maxs = sum;
		}
		return;
	}
	int i = (curr == 0) ? 0 : cList[curr - 1] + 1;
	for(; i < n; i++) {
		bool isFound = false;
		for(int j = 0; j < curr; j++) {
			if(i == cList[j]) {
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			if(addComb(i)) {
				cList[curr] = i;
				dfs(curr + 1);
				subComb(i);
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int a, b, c, s;
	int count = 0;
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		
		for(int i = 0; i < n; i++) {
			cin >> a >> b >> c >> s;
			comList[i][0] = a;
			comList[i][1] = b;
			comList[i][2] = c;
			comList[i][3] = s;
		}
		if(n < 3) {
			cout << "Case " << ++count << ": -1" << endl;
			continue;
		}
		maxs = -1;
		dfs(0);
		cout << "Case " << ++count << ": " << maxs << endl;
	}
	

	return 0;
}