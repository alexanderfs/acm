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
#include <cstring>
using namespace std;

int valList[1000];
int n;

int calResult(int n)
{
	int v = 0;
	while(n) {
		int a = n % 10;
		v += a * a;
		n = n / 10;
	}
	return v;
}

bool isValid(int v)
{
	if(v == n) {
		return false;
	}
	if(valList[v] == 0) {
		valList[v] = 1;
		return true;
	} else if(valList[v] == 1) {
		return false;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int num;
	cin >> num;
	int count = 0;
	
	while(num--) {
		cin >> n;
		memset(valList, 0, sizeof(valList));
		int v = calResult(n);
		bool va = isValid(v);
		while(va && v != 1) {
			v = calResult(v);
			va = isValid(v);
		}
		if(v == 1) {
			cout << "Case #" << ++count << ": " << n << " is a Happy number." << endl;
		} else {
			cout << "Case #" << ++count << ": " << n << " is an Unhappy number." << endl;
		}
	}

	return 0;
}