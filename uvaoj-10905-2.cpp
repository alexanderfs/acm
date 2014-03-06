/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 很巧妙的比较方法。大牛果然是大牛 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector> 
using namespace std;

int n;
vector<string> nList;

bool comp(const string &a, const string &b)
{
	if(a.size() == b.size()) {
		return a > b;
	}
	string c1 = a + b;
	string c2 = b + a;
	return c1 > c2;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		string tmp;
		nList.clear();
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			nList.push_back(tmp);
		}
		sort(nList.begin(), nList.end(), comp);
		string maxStr = accumulate(nList.begin(), nList.end(), string(""));
		cout << maxStr << endl;
	}

	return 0;
}