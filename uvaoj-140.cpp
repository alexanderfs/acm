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
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int graph[26][26];
int evolve[26];
int iList[8];
int cList[8];
int mcList[8];
int minbw = 1000000000;
int n;
int xcount;

int calBW()
{
	int val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[cList[i]][cList[j]]) {
				int dis = i - j;
				if (dis < 0) {
					dis = -dis;
				}
				if (dis > val) {
					val = dis;
				}
			}
		}
	}
	return val;
}

void getMinBW(int curr)
{
	xcount++;
	if (curr == n) {
		int bw = calBW();
		/*cout << "test: ";
		for (int i = 0; i < n; i++) {
			cout << cList[i] << " ";
		}
		cout << "-> " << bw << endl;*/
		if (bw < minbw) {
			minbw = bw;
			memcpy(mcList, cList, sizeof(cList));
		}
		return;
	}

	for (int c = 0; c < n; c++) {
		int i = iList[c];
		bool isFound = false;
		for (int j = 0; j < curr; j++) {
			if (cList[j] == i) {
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			bool isValid = true;
			for (int k = 0; k < curr; k++) {
				if (graph[cList[k]][i] && (curr - k > minbw)) {
					isValid = false;
				}
			}
			if (isValid) {
				cList[curr] = i;
				getMinBW(curr + 1);
			}
		}
	}
}


void cleanJob()
{
	minbw = 1000000000;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			graph[i][j] = 0;
		}
	}
	n = 0;
	memset(evolve, 0, sizeof(evolve));
	memset(cList, 0, sizeof(cList));
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string str;
	while (getline(cin, str)) {
		if (str[0] == '#') {
			break;
		}
		int start = str.find(':', 0);
		while (start != string::npos) {
			int a = str[start - 1] - 'A';
			evolve[a] = 1;
			start++;
			while (start < str.size() && str[start] != ';') {
				int b = str[start] - 'A';
				evolve[b] = 1;
				graph[a][b] = graph[b][a] = 1;
				start++;
			}
			if (start == str.size()) {
				break;
			}
			start = str.find(':', start);
		}

		for (int i = 0; i < 26; i++) {
			if (evolve[i]) {
				iList[n++] = i;
			}
		}

		getMinBW(0);
		for (int i = 0; i < n; i++) {
			cout << static_cast<char>(mcList[i] + 'A') << " ";
		}
		cout << "-> " << minbw << endl;
		//cout << xcount << endl;

		cleanJob();
	}

	return 0;
}