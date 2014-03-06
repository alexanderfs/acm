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
using namespace std;

string s1, s2;
int n1, n2;
int d[105][105];
bool v[105][105];
int dx[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};

int dp(int i1, int i2)
{
	if(i1 < 0 || i2 < 0) {
		return 0;
	}
	if(v[i1][i2]) {
		return d[i1][i2];
	}
	v[i1][i2] = true;
	for(int i = 0; i < 3; i++) {
		if(i == 0 && s1[i1] == s2[i2]) {
			int val = 1 + dp(i1 + dx[i][0], i2 + dx[i][1]);
			if(d[i1][i2] < val) {
				d[i1][i2] = val;
			}
		}
		int val = dp(i1 + dx[i][0], i2 + dx[i][1]);
		if(d[i1][i2] < val) {
			d[i1][i2] = val;
		}	
	}
	return d[i1][i2];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 0;
	while(true) {
		getline(cin, s1);
		if(s1[0] == '#') {
			break;
		}
		getline(cin, s2);
		n1 = s1.size();
		n2 = s2.size();
		memset(d, 0, sizeof(d));
		memset(v, false, sizeof(v));
		cout << "Case #" << ++count << ": you can visit at most " << dp(n1 - 1, n2 - 1) << " cities." << endl;
	}

	return 0;
}