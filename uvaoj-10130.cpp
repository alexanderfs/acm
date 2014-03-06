/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 真尼玛无聊这题！！看来以后实例程序也得稍微看一下，
 这样会有助于读懂题意啊。话说如果这题真的像我想的那样该怎么做？ 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int objList[1005][3];
int on;
int pList[105];
int pn;
int f[1005][35];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> on;
		for(int i = 1; i <= on; i++) {
			cin >> objList[i][0] >> objList[i][1];
			objList[i][2] = 0;
		}
		cin >> pn;
		int sum = 0;
		for(int i = 0; i < pn; i++) {
			cin >> pList[i];
			for(int j = 1; j <= on; j++) {
				for(int k = 1; k <= pList[i]; k++) {
					f[j][k] = f[j - 1][k];
					if(k >= objList[j][1] && f[j][k] < f[j - 1][k - objList[j][1]] + objList[j][0]) {
						f[j][k] = f[j - 1][k - objList[j][1]] + objList[j][0];
					}
				}
			}
			//cout << "this round: " << f[on][pList[i]] << endl;
			sum += f[on][pList[i]];
			/*int val = pList[i];
			for(int j = on; j > 0; j--) {
				if(f[j][val] == f[j - 1][val]) {
					continue;
				}
				for(int k = val; k > 0; k--) if(k >= objList[j][1]){
					if(f[j][val] == f[j - 1][k - objList[j][1]] + objList[j][0]) {
						val -= objList[j][1];
						objList[j][2] = 1;
					 	//cout << objList[j][0] << ", " << objList[j][1] << endl;
						break;
					}
				}
			}*/
			memset(f, 0, sizeof(f));
		}
		cout << sum << endl;
		
	}
	return 0;
}