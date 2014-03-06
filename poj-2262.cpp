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

bool numList[1000005]; 

void buildPrimList()
{
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * i; j < 1000000; j += i) {
			numList[j] = true;
		}
	}
	numList[2] = numList[1] = numList[0] = true;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	buildPrimList();
	int num;
	while(cin >> num) {
		if(!num) {
			break;
		}
		for(int i = num; i >= num / 2; i--) if(!numList[i]){
			if(numList[num - i] == false) {
				cout << num << " = " << num - i << " + " << i << endl;
				break;
			}
		}
	}

	return 0;
}