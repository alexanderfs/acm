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
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

vector<int> numList;
string mystr;

int main() {
	ifstream insss("test_input.txt");
	cin.rdbuf(insss.rdbuf());
	while(getline(cin, mystr)) {
		stringstream ss(mystr);
		char tmpc;
		int tmpn;
		int len = 0;
		ss >> tmpn;
		numList.push_back(tmpn);
		len++;
		while(ss >> tmpc >> tmpn) {
			numList.push_back(tmpn);
			len++;
		}
		
		int inCount = 0;
		for(int i = 0; i < len; i++) {
			for(int j = i + 1; j < len; j++) if(numList[i] > numList[j]) {
				inCount++;
			}
		}
		if(!inCount) {
			cout << 0 << endl;
			numList.clear();
			continue;
		}
		int minCount = inCount;
		int currCount = inCount;
		for(int i = 0; i < len; i++) {
			for(int j = i + 1; j < len; j++)  {
				if(numList[i] > numList[j])
					currCount = inCount - 1;
			 	else
			 		currCount = inCount;
				int a = numList[i];
				int b = numList[j];
				for(int i1 = i + 1; i1 < j; i1++) {
					if(b < numList[i1] && a > numList[i1]) {
						currCount--;
					}
					if(a < numList[i1] && b > numList[i1]) {
						currCount++;
					}
				}
				if(currCount < minCount) {
					minCount = currCount;
				}
			}
		}
		cout << minCount << endl;
		numList.clear();
	}

	return 0;
}