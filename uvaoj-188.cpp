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
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string tmp;
	vector<string> wordList;
	vector<int> valueList;
	while(getline(cin, tmp)) {
		stringstream ss(tmp);
		string tmp1;
		wordList.clear();
		while(ss >> tmp1) {
			wordList.push_back(tmp1);
		}
		valueList.clear();
		int vt;
		for(int i = 0; i < wordList.size(); i++) {
			vt = 0;
			for(int j = 0; j < wordList[i].size(); j++) {
				vt = (vt << 5) + wordList[i][j] - 'a' + 1;
			}
			valueList.push_back(vt);
		}
		sort(valueList.begin(), valueList.end());
		int c = valueList[0];
		restart:
		for(int i = 0; i < valueList.size(); i++) {
			for(int j = 0; j < valueList.size(); j++) if(i != j){
				int n1 = c / valueList[i];
				int n2 = c / valueList[j];
				if(n1 % valueList.size() == n2 % valueList.size()) {
					int nc1 = (n1 + 1) * valueList[i];
					int nc2 = (n2 + 1) * valueList[j];
					c = nc1 > nc2 ? nc2 : nc1;
					goto restart;
				}
			}
		}
		cout << tmp << endl;
		cout << c << endl;
		cout << endl;
	}
	return 0;
}