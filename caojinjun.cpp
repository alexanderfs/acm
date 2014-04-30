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
#include <cstdio>
using namespace std;

int byteList[7] = {1, 1, 2, 2, 2, 4, 4};
char nameList[7][12] = {"Type", "Command", "Port", "Result", "TransMode", "RateUp", "RateDown"};

int main()
{
	//ifstream in("test_input.txt");
	//cin.rdbuf(in.rdbuf());
	//freopen("test_input.txt", "r", stdin);
	int val;
	for(int i = 0; i < 7; i++) {
		int val = 0;
		int sum = 0;
		for(int j = 0; j < byteList[i]; j++) {
			scanf("%x", &val);
			sum = sum * 256 + val;
		}
		printf("%s=%d\n", nameList[i], sum);
	}
	
	return 0;
}