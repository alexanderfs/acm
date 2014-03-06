/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 不知道怎么回事改成这样了还是过不了 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
using namespace std;

string ra, rb;
string w, z;
set<string> ss;

bool isExist(string &str)
{
	if(ss.count(str)) {
		return true;
	} else {
		ss.insert(str);
		return false;
	}
}

bool bfs()
{
	queue<string> sq;
	ss.clear();
	if(w.size() >= z.size()) {
		for(int i = 0; i < w.size(); i++) {
			string tmp;
			for(int j = i; j < w.size() && j - i < z.size(); j++) {
				tmp += w[j];
			}
			if(tmp == z) {
				return 0;
			} else if(isExist(tmp) == false) {
				sq.push(tmp);
			}
		}
	} else {
		ss.insert(w);
		sq.push(w);
	}
	
	while(sq.empty() == false && sq.size() < 10000) {
		string first = sq.front();
		sq.pop();
		string nstr;
		for(int i = 0; i < first.size(); i++) {
			if(first[i] == 'a') {
				nstr += ra;
			} else {
				nstr += rb;
			}
		}
		for(int i = 0; i < nstr.size(); i++) {
			string tmp;
			for(int j = i; j < nstr.size() && j - i < z.size(); j++) {
				tmp += nstr[j];
			}
			if(tmp == z) {
				return true;
			} else if(isExist(tmp) == false){
				sq.push(tmp);
			}
		}
				
	}
	return false;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> ra >> rb >> w) {
		cin.get();
		getline(cin, z);
		if(z.empty() || bfs()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}