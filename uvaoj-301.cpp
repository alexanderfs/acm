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

typedef struct order {
	int start;
	int end;
	int opn;
} ORDER;

int pn, bn, ln;
ORDER olist[22];
int clist[22];
int mearning;
int earning;
int tstat[8];

void cleanJob()
{
	mearning = earning = 0;
	memset(tstat, 0, sizeof(tstat));
}

bool checkValid(int p)
{
	for(int i = olist[p].start; i < olist[p].end; i++) {
		if(tstat[i] + olist[p].opn > pn) {
			return false;
		}
	}
	return true;
}

void updateStat(int c)
{
	for(int i = olist[c].start; i < olist[c].end; i++) {
		tstat[i] += olist[c].opn;
	}
}

void rollbackStat(int c)
{
	for(int i = olist[c].start; i < olist[c].end; i++) {
		tstat[i] -= olist[c].opn;
	}
}

int calEarning(int len)
{
	int sum = 0;
	for(int i = 0; i < len; i++) {
		sum += (olist[clist[i]].end - olist[clist[i]].start) * 
			olist[clist[i]].opn;
	}
	return sum;
}

void dfs(int curr)
{
	if(curr == ln) {
		earning = calEarning(curr);
		if(earning > mearning) {
			mearning = earning;
		}
		/*for(int k = 0; k < curr; k++) {
			cout << clist[k] << " ";
		}
		cout << endl;*/
		return;
	}
	
	bool isCalc = false;
	for(int i = 0; i < ln; i++) if(curr == 0 || clist[curr - 1] < i){
		bool isFound = false;
		for(int j = 0; j < curr; j++) {
			if(clist[j] == i) {
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			if(checkValid(i)) {
				clist[curr] = i;
				updateStat(i);
				dfs(curr + 1);
				rollbackStat(i);
			} else if(!isCalc){
				earning = calEarning(curr);
				if(earning > mearning) {
					mearning = earning;
				}
				/*for(int k = 0; k < curr; k++) {
					cout << clist[k] << " ";
				}
				cout << endl;*/
				isCalc = true;
			}
		}
	}
	if(curr < ln) {
		earning = calEarning(curr);
		if(earning > mearning) {
			mearning = earning;
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> pn >> bn >> ln) {
		if(!pn && !bn && !ln) {
			break;
		}
		for(int i = 0; i < ln; i++) {
			cin >> olist[i].start >> olist[i].end >> olist[i].opn;
		}
		dfs(0);
		cout << mearning << endl;
		//cout << endl;
		cleanJob();
	}

	return 0;
}