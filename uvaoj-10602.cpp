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
#include <string>
#include <algorithm>

using namespace std;

string firstStr;

struct mySort {
	mySort(int c = 0):fc(c) {}
	int fc;
	bool operator() (const string &a, const string &b) {
		/*if(a[0] != firstStr[0] && b[0] != firstStr[0]) {
			return a < b;
		}*/
		int c1 = 0;
		int i = 0;
		while(i < a.size() && i < firstStr.size() && a[i] == firstStr[i]) {
			i++;
			c1++;
		}
		int c2 = 0;
		i = 0;
		while(i < b.size() && i < firstStr.size() && b[i] == firstStr[i]) {
			i++;
			c2++;
		}
		if(c1 == c2) {
			return a < b;
		}
		return c1 > c2;
	}
};

vector<string> strList;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		strList.clear();
		int n;
		cin >> n;
		string str;
		for(int i = 0; i < n; i++) {
			cin >> str;
			strList.push_back(str);
		}
		firstStr = strList[0];
		sort(strList.begin()+1, strList.end(), mySort(strList[0][0]));
		
		int tc = strList[0].size();
		for(int i = 1; i < strList.size(); i++) {
			int n1 = 0;
			while(n1 < strList[i - 1].size() && n1 < strList[i].size() &&
				strList[i - 1][n1] == strList[i][n1]) {
				n1++;	
			}
			tc += (strList[i].size() - n1);
		}
		cout << tc << endl;
		for(int i = 0; i < strList.size(); i++) {
			cout << strList[i] << endl;
		}
		//cout << endl;
	}

	return 0;
}