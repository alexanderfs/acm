/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 你真的没有意识到这样根本是不可能的么。。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;

string firstStr;
set<string> strSet;
vector<string> strQueue;
int layerList[1000000];

bool isPali(string &str)
{
	for(int i = 0, j = str.size() - 1; i < j; i++, j--) {
		if(str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

void bfs()
{
	strQueue.clear();
	strSet.clear();
	int front = 0;
	int rear = 0;
	if(isPali(firstStr)) {
		cout << 0 << endl;
		return;
	}
	strQueue.push_back(firstStr);
	rear++;
	strSet.insert(firstStr);
	layerList[front] = 0;
	while(front < rear) {
		string tmp = strQueue[front];
		//cout << front << ", " << rear << ": " << tmp << endl;
		for(int i = 1; i < tmp.size(); i++) {
			char tc = tmp[i - 1];
			tmp[i - 1] = tmp[i];
			tmp[i] = tc;
			if(isPali(tmp)) {
				cout << layerList[front] + 1 << endl;
				return;
			}
			if(strSet.count(tmp) == 0) {
				strQueue.push_back(tmp);
				strSet.insert(tmp);
				layerList[rear++] = layerList[front] + 1;
			}
			tc = tmp[i - 1];
			tmp[i - 1] = tmp[i];
			tmp[i] = tc;
		}
		front++;
	}
	cout << "Impossible" << endl;
	return;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tnc;
	cin >> tnc;
	while(tnc--) {
		cin >> firstStr;
		bfs();
	}

	return 0;
}
