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

int aid;
int len;
char statestr[35];
int stat[35];
int rule[8];
int clist[35];
int maplist[8][3] =
{ { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 0 },
{ 0, 1, 1 }, { 1, 0, 0 }, { 1, 0, 1 },
{ 1, 1, 0 }, { 1, 1, 1 } };

void cleanJob()
{
	//	memset(statestr, 0, sizeof(statestr));
	//	memset(stat, 0, sizeof(stat));
	memset(rule, 0, sizeof(rule));
	//	memset(clist, 0, sizeof(clist));
}


bool dfs(int curr)
{
	if (curr == len - 1) {
		for (int i = 0; i < 8; i++) {
			if (stat[curr] == rule[i] &&
				clist[curr - 1] == maplist[i][0] &&
				clist[curr] == maplist[i][1] &&
				clist[curr + 1] == maplist[i][2]) {
				return dfs(curr + 1);
			}
		}
		return false;
	}
	if (curr == len) {
		for (int i = 0; i < 8; i++) {
			if (stat[curr] == rule[i] &&
				clist[curr - 1] == maplist[i][0] &&
				clist[curr] == maplist[i][1] &&
				clist[curr + 1] == maplist[i][2]) {
				return true;
			}
		}
		return false;
	}
	bool re = false;
	for (int i = 0; i < 8; i++) {
		if (stat[curr] == rule[i] &&
			clist[curr - 1] == maplist[i][0] &&
			clist[curr] == maplist[i][1]) {
			clist[curr + 1] = maplist[i][2];
			re = dfs(curr + 1);
			if (re) {
				return true;
			}
		}
	}
	return re;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while (cin >> aid >> len >> statestr) {
		cleanJob();
		int tmp = aid;
		int idx = 0;
		while (tmp > 0) {
			rule[idx++] = tmp % 2;
			tmp >>= 1;
		}
		bool all0 = true;
		bool all1 = true;
		for (int i = 0; i < len; i++) {
			stat[i + 1] = statestr[i] - '0';
			if (statestr[i] == '0') {
				all1 = false;
			}
			if (statestr[i] == '1') {
				all0 = false;
			}
		}
		
		if (aid == 204) {
			cout << "REACHABLE" << endl;
			continue;
		}
		if (aid == 0 && all0) {
			cout << "REACHABLE" << endl;
			continue;
		}
		else if (aid == 0 && !all0) {
			cout << "GARDEN OF EDEN" << endl;
			continue;
		}

		if (aid == 255 && all1) {
			cout << "REACHABLE" << endl;
			continue;
		}
		else if (aid == 255 && !all1) {
			cout << "GARDEN OF EDEN" << endl;
			continue;
		}

		bool result = false;
		for (int i = 0; i < 8; i++) {
			if (stat[1] == rule[i]) {
				clist[0] = clist[len] = maplist[i][0];
				clist[1] = clist[len + 1] = maplist[i][1];
				clist[2] = maplist[i][2];
				if (dfs(2)) {
					result = true;
					break;
				}
			}
		}
		if (result) {
			cout << "REACHABLE" << endl;
		}
		else {
			cout << "GARDEN OF EDEN" << endl;
		}


	}
	
	return 0;
}