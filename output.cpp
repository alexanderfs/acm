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

const int len = 1000;

int main()
{
	ofstream out("test_input.txt");
	cout.rdbuf(out.rdbuf());
	
	cout << len << endl;
	for(int i = 1; i <= len; i++) {
		cout << i << endl;
	}

	return 0;
}