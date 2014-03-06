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
#include <cmath>
#include <cstring>
using namespace std;

const int MAXINT = 10000;
int n;
int primList[1500];
int pn;
bool numList[MAXINT + 5];

void buildPrimList()
{
	for(int i = 2; i <= MAXINT; i++) {
		for(int j = i * i; j <= MAXINT; j += i) {
			numList[j] = true;
		}
	}
	for(int i = 2; i <= MAXINT; i++) if(!numList[i]){
		primList[pn++] = i;
		//cout << i << " ";
	}
	//cout << endl;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	buildPrimList();
	while(cin >> n) {
		if(!n) {
			break;
		}
		int count = 0;
		for(int i = 0; i < pn && primList[i] <= n; i++) {
			int tmpsum = 0;
			for(int j = i; j < pn && tmpsum	< n; j++) {
				tmpsum += primList[j];
			}
			if(tmpsum == n) {
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}