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
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int n1[26];
	int n2[26];
	memset(n1, 0, sizeof(n1));
	memset(n2, 0, sizeof(n2));
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	if(len1 != len2) {
		cout << "NO" << endl;
	} else {
		for(int i = 0; i < len1; i++) {
			n1[s1[i] - 'A']++;
			n2[s2[i] - 'A']++;
		}
		sort(n1, n1 + 26);
		sort(n2, n2 + 26);
		if(memcmp(n1, n2, sizeof(n1)) == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}