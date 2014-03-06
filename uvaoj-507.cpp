/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 说实话你的分析能力真不咋地 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int assessList[20005];
int s;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	int rc = 0;
	cin >> tcn;
	while(tcn--) {
		cin >> s;
		for(int i = 1; i < s; i++) {
			cin >> assessList[i];
		}
		int sum = 0;
		int max = 0;
		int start = 0;
		int end = 0;
		int ms = 0;
		int me = 0;
		for(int i = 1; i < s; i++) {
			if(sum + assessList[i] < 0) {
				sum = 0;
				start = end = i;
			} else {
				sum += assessList[i];
				if(max <= sum) {
					end = i;
					if((max == sum && end - start > me - ms) || max < sum) {
						me = end;
						ms = start;
					}
					max = sum;	
				}
			}
		}
		if(max <= 0) {
			cout << "Route " << ++rc << " has no nice parts" << endl;
		} else {
			cout << "The nicest part of route " << ++rc << " is between stops " << ms + 1 << " and " << me + 1 << endl;
		}
	}

	return 0;
}