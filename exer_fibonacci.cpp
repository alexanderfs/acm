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

using namespace std;

class Fibonacci {
public:
	int calFibonacci(int n);
};

int Fibonacci::calFibonacci(int n) {
	if(n < 2) {
		return n;
	}
	int x = 0;
	int y = 1;
	int result;
	for(int i = 1; i < n; i++) {
		result = x + y;
		x = y;
		y = result;
	}
	return result;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	Fibonacci fo;
	for(int i = 0; i < 10; i++) {
		cout << fo.calFibonacci(i) << endl;
	}
	
	return 0;
}