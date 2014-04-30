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

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m;
vector<string> strList;

bool mycomp(string s1, string s2) {
	string cs1, cs2;
	cs1 = s1 + s2;
	cs2 = s2 + s1;
	return cs1 < cs2;
}

int main() {
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> m) {
		string tmp;
		for(int i = 0; i < m; i++) {
			cin >> tmp;
			strList.push_back(tmp);
		}
		sort(strList.begin(), strList.end(), mycomp);
		for(int i = 0; i < m; i++) {
			cout << strList[i];
		}
		cout << endl;
		strList.clear();
	}
	

	return 0;
}