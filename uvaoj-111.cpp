/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 最长公共子序列。该看书了。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int correctList[25];
int n;
int studentList[25];
int c[25][25];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	cin >> n;
	int tmp;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		correctList[tmp] = i;
	}
	bool isDone = false;
	while(true) {
		for(int i = 1; i <= n; i++) {
			if(!(cin >> tmp)) {
				isDone = true;
				break;
			} else {
				studentList[tmp] = i;
			}
		}
		if(isDone) {
			break;
		}
		memset(c, 0, sizeof(c));
		
		c[1][1] = (correctList[1] == studentList[1]);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) if(i != 1 || j != 1){
				int val[3];
				val[0] = (correctList[i] == studentList[j]) + c[i - 1][j - 1];
				val[1] = c[i - 1][j];
				val[2] = c[i][j - 1];
				int max = val[0];
				if(val[1] > max) {
					max = val[1];
				}
				if(val[2] > max) {
					max = val[2];
				}
				c[i][j] = max;
				
			}
		}
		cout << c[n][n] << endl;
	}

	return 0;
}