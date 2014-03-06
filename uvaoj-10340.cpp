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
#include <string>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string s1, s2;
	while(cin >> s1 >> s2) {
		int j = 0;
		bool isOk = true;
		for(int i = 0; i < s1.size(); i++) {
			while(j < s2.size() && s2[j] != s1[i]) {
				j++;
			}
			
			if(j == s2.size() && i < s1.size()) {
				isOk = false;
				break;
			}
			if(j < s2.size()) {
				j++;
			}
		}
		if(isOk) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}