/*******************************************************************
* Copyright (C) Alex AN
*
* File Name   :
* Author      : Alex AN
* Create      :
* Mail        : alexbupt@gmail.com
* Blog        : http://blog.csdn.net/alexbupt
*
* Description : Éî¶ÈËÑË÷£¬³¬Ê± 
*
******************************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct filenode {
	int i1, i2;
	string comb;
};

int n;
int lmin, lmax;
vector<string> fragList;
vector<int> visitList;
vector<int> tryList;
vector<string> candList;

bool isExist(string s)
{
	for (int i = 0; i < candList.size(); i++) {
		if (s == candList[i]) {
			return true;
		}
	}
	return false;
}

void dfs(int curr)
{
	if (curr == fragList.size()) {
		//cout << fragList[tryList[curr - 2]] + fragList[tryList[curr - 1]] << endl;
		string tmp = fragList[tryList[curr - 2]] + fragList[tryList[curr - 1]];
		if (!isExist(tmp)) {
			candList.push_back(tmp);
		}
		return;
	}
	int idx = 0;
	while (idx < fragList.size()) {
		while (idx < fragList.size() && visitList[idx] == 1) {
			idx++;
		}
		if (idx == fragList.size()) {
			break;
		}
		tryList[curr] = idx;
		visitList[idx] = 1;
		for (int i = 0; i < fragList.size(); i++) {
			if (i != idx &&
				(fragList[i].size() + fragList[tryList[curr]].size() == lmin + lmax) &&
				visitList[i] == 0 &&
				(curr < 2 || (fragList[tryList[curr]] + fragList[i]) == fragList[tryList[curr - 2]] + fragList[tryList[curr - 1]])
				) {
				visitList[i] = 1;
				tryList[curr + 1] = i;
				dfs(curr + 2);
				visitList[i] = 0;
			}
		}
		visitList[idx] = 0;
		idx++;
	}
	/*for (idx = 0; visitList[idx] == 1; idx++) {
	;
	}
	tryList[curr] = idx;
	visitList[idx] = 1;
	for (int i = 0; i < fragList.size(); i++) {
	if (i != idx &&
	(fragList[i].size() + fragList[tryList[curr]].size() == lmin + lmax) &&
	visitList[i] == 0 &&
	(curr < 2 || (fragList[tryList[curr]] + fragList[i]) == fragList[tryList[curr - 2]] + fragList[tryList[curr - 1]])
	) {
	visitList[i] = 1;
	tryList[curr + 1] = i;
	dfs(curr + 2);
	visitList[i] = 0;
	}
	}
	visitList[idx] = 0;*/
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	cin >> n;
	char c = cin.get();
	c = cin.get();
	while (n--) {
		fragList.clear();
		lmin = ~(1 << 31);
		lmax = 0;
		while (true) {
			string tmp;
			getline(cin, tmp);
			if (tmp.empty()) {
				break;
			}
			fragList.push_back(tmp);
			if (tmp.size() > lmax) {
				lmax = tmp.size();
			}
			if (tmp.size() < lmin) {
				lmin = tmp.size();
			}
		}
		visitList.clear();
		visitList.resize(fragList.size(), 0);
		tryList.clear();
		tryList.resize(fragList.size());
		candList.clear();
		dfs(0);
		for (int i = 0; i < candList.size(); i++) {
			cout << candList[i] << endl;
		}
		if (n != 0) {
			cout << endl;
		}
	}

	return 0;
}