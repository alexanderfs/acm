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
#include <set>
#include <string>
using namespace std;

set<string> dict;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string tmp;
	while(cin >> tmp) {
		dict.insert(tmp);
	}
	for(set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
		string curr = *iter;
		for(int i = 1; i < curr.size(); i++) {
			string sub1;
			string sub2;
			for(int j = 0; j < i; j++) {
				sub1 += curr[j];
			}
			for(int j = i; j < curr.size(); j++) {
				sub2 += curr[j];
			}
			if(!sub1.empty() && !sub2.empty()) {
				if(dict.count(sub1) > 0 && dict.count(sub2) > 0) {
					cout << curr << endl;
					break;
				}
			}
		}
	}
	return 0;
}