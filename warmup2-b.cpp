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
using namespace std;

int numList[105];
int n;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> numList[i];
		}
		sort(numList, numList + n);
		int val = numList[0];
		int vcount = 1;
		int tcount = 0;
		for(int i = 1; i < n; i++) {
			if(numList[i] == val) {
				vcount++;
			} else {
				if(vcount >= 3) {
					tcount++;
				}
				vcount = 1;
				val = numList[i];
			}
		}
		if(vcount >= 3) {
			tcount++;
		}
		cout << tcount << endl;
	}

	return 0;
}