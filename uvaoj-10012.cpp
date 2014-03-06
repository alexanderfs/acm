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
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
double rlist[8];
int ilist[8];
int num;
double len;
double minLen = 1000000000;

double calDis(double r1, double r2)
{
	return sqrt((r1 + r2) * (r1 + r2) - (r1 - r2) * (r1 - r2));
}

void dfs(double cd, int idx, bool isJump)
{
	if(idx != num && cd > minLen) {
		return;
	}
	if(idx == num) {
		cd += rlist[ilist[idx -1]];
		if(cd < minLen) {
			minLen = cd;
			for(int i = 0; i < num; i++) {
				cout << rlist[ilist[i]] << " ";
			}
			cout << endl; 
		}	
		return;
	}
	for(int i = 0; i < num; i++) {
		bool isFound = false;
		for(int j = 0; j < idx; j++) {
			if(ilist[j] == i) {
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			if(idx == 0) {
				ilist[idx] = i;
				dfs(rlist[i], idx + 1);
			} else {
				double dis = calDis(rlist[idx - 1], rlist[i]);
				
				if(rlist[idx - 1] < rlist[i] && dis < rlist[i]) {
					
				}
			}
		}
		if(!isFound) {
			if(idx == 0) {
				ilist[idx] = i;
				dfs(rlist[i], idx + 1, false);
			} else if(idx == 1) {
			
			} 
				else {
				double dis;
				if(!isJump) {
					dis = calDis(rlist[ilist[idx - 1]], rlist[i]);
				} else {
					dis = calDis(rlist[ilist[idx - 2]], rlist[i]);
				}
				
				ilist[idx] = i;
				if(dis < rlist[ilist[idx - 1]]) {
					dfs(cd + rlist[ilist[idx - 1]], idx + 1, true);
				} else {
					dfs(cd + dis, idx + 1, false);
				}
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	
	cin >> count;
	while(count--) {
		cin >> num;
		for(int i = 0; i < num; i++) {
			cin >> rlist[i];
		}
		
		dfs(0, 0, false);
		cout << fixed << setprecision(3) << minLen << endl;
		len = 1000000000;
		minLen = 1000000000;
		
	}
	return 0;
}