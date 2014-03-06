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

int n;
int mat[105][105];
int flat[105];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	int maxmax = 1 << 31;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			memset(flat, 0, sizeof(flat));
			for(int k = 0; k < n; k++) {
				for(int x = i; x <= j; x++) {
					flat[k] += mat[x][k];
				}
			}
			int sum = 0;
			int max = 0;
			for(int k = 0; k < n; k++) {
				if(sum + flat[k] < 0) {
					sum = 0;
				} else {
					sum += flat[k];
					if(sum > max) {
						max = sum;
					}
				}
			}
			if(max == 0) {
				max = flat[0];
				for(int k = 1; k < n; k++) {
					if(max < flat[k]) {
						max = flat[k];
					}
				}
			}
			if(max > maxmax) {
				maxmax = max;
			}
		}
	}
	cout << maxmax << endl;
	return 0;
}