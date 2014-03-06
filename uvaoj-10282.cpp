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
#include <sstream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string tmp;
	string t1, t2;
	map<string, string> dict;
	while(true) {
		getline(cin, tmp);
		if(tmp.empty() == true) {
			break;
		}
		stringstream ss(tmp);
		ss >> t1 >> t2;
		dict[t2] = t1;
	}
	while(cin >> tmp) {
		if(dict.count(tmp)) {
			cout << dict[tmp] << endl;
		} else {
			cout << "eh" << endl;
		}
	}
	return 0;
}