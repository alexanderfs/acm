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
#include <algorithm>
using namespace std;
int n;
char naturalNum[100];

bool dfs(int n, int curr)
{
	if(n < 10 && n > 0) {
		naturalNum[curr] = '0' + n;
		sort(naturalNum, naturalNum + curr + 1);
		naturalNum[curr + 1] = '\0';
		cout << naturalNum << endl;
		return true;
	} else if(n == 0) {
		sort(naturalNum, naturalNum + curr);
		naturalNum[curr] = '\0';
		cout << naturalNum << endl;
		return true;
	}
	
	for(int i = 9; i > 1; i--) {
		if(n % i == 0) {
			naturalNum[curr] = '0' + i;
			return dfs(n / i, curr + 1);
		}
	}
	return false;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> n;
		memset(naturalNum, 0, sizeof(naturalNum));
		if(!dfs(n, 0)) {
			cout << -1 << endl;
		}
	}

	return 0;
}