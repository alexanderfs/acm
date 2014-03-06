/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 可以设一个访问数组来判断这个有没有计算过，这样就不用
 在开始的时候把所有的都计算出来了 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int num;
int d[10000];
int c[5] = {1, 5, 10, 25, 50};

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	d[0] = 1;
	for(int i = 0; i < 5; i++) {
		for(int j = 1; j < 7500; j++) if(j >= c[i]){
			d[j] = d[j] + d[j - c[i]];
		}
	}
	while(cin >> num) {
		cout << d[num] << endl;
	}

	return 0;
}