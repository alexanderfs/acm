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
	string str;
	while(true) {
		getline(cin, str);
		if(str[0] == '#') {
			break;
		}
		int sum = 0;
		int len = str.size();
		for(int i = 0; i < len; i++) if(str[i] != ' '){
			sum += (i + 1) * (str[i] - 'A' + 1);
		}
		cout << sum << endl;
	}

	return 0;
}