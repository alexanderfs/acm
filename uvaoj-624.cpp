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

int trackList[25];
int n;
int tn;
int nList[25][1000];

void printResult(int idx)
{
	for(int i = tn; i > 0; i--) {
		if(nList[i][idx] == nList[i - 1][idx]) {
			continue;
		}
		for(int j = idx; j > 0; j--) if(nList[i][idx] == nList[i - 1][idx - trackList[i]] + trackList[i]) {
			cout << trackList[i] << " ";
			idx -= trackList[i];
			break;
		}
	}
	cout << "sum:" << nList[tn][n] << endl;
}

void printResult(int lay, int amount)
{
	if(lay == 0) {
		return;
	}
	if(nList[lay][amount] == nList[lay - 1][amount]) {
		printResult(lay - 1, amount);
		return;
	}
	for(int j = amount; j > 0; j--) if(nList[lay][amount] == nList[lay - 1][amount - trackList[lay]] + trackList[lay]) {
		printResult(lay - 1, amount - trackList[lay]);
		cout << trackList[lay] << " ";
		return;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {	
		cin >> tn;
		for(int i = 1; i <= tn; i++) {
			cin >> trackList[i];
		}
		for(int i = 1; i <= tn; i++) {
			for(int j = 1; j <= n; j++) {
				nList[i][j] = nList[i - 1][j];
				if(j >= trackList[i] && nList[i][j] < nList[i - 1][j - trackList[i]] + trackList[i]) {
					nList[i][j] = nList[i - 1][j - trackList[i]] + trackList[i];
				}
			}
		}
		printResult(tn, n);
		cout << "sum:" << nList[tn][n] << endl;
	}
	
	return 0;
}