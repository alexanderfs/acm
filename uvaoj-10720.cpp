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
#include <algorithm>
#include <cstring>
using namespace std;

int degList[10005];
int zeroList[10005];

bool myComp(int a, int b)
{
	return a > b;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int n;
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			cin >> degList[i];
		}
		int start = 0;
		bool isValid = true;
		while(isValid) {
			sort(degList + start, degList + n, myComp);
			int max = degList[start];
			degList[start] = 0;
			for(int i = start + 1; i <= start + max; i++) {
				if(i >= n) {
					isValid = false;
					break;
				}
				degList[i] -= 1;
				if(degList[i] < 0) {
					isValid = false;
					break;
				}	
			}
			if(isValid && memcmp(degList, zeroList, sizeof(int) * n) == 0) {
				break;
			} else {
				start++;
			}
		}
		if(isValid) {
			cout << "Possible" << endl;
		} else {
			cout << "Not possible" << endl;
		}
	}
	return 0;
}