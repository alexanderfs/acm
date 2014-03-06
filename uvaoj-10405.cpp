/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 字符串类题出现WA需要考虑是不是输入有空格的情况 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string s1;
string s2;
int d[1005][1005];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	while(true) {
		getline(cin, s1);
		if(!cin) {
			break;
		}
		getline(cin, s2);
		int len1 = s1.size();
		int len2 = s2.size();
		for(int i = 1; i <= len1; i++) {
			for(int j = 1; j <= len2; j++) {
				d[i][j] = (s1[i - 1] == s2[j - 1]) + d[i - 1][j - 1];
				if(d[i][j] < d[i][j - 1]) {
					d[i][j] = d[i][j - 1];
				}
				if(d[i][j] < d[i - 1][j]) {
					d[i][j] = d[i - 1][j];
				}
			}
		}
		cout << d[len1][len2] << endl;
	}
	return 0;
}