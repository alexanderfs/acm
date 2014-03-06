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
#include <set>
#include <vector>
using namespace std;

vector<string> lang1;
vector<string> lang2;
set<string> conclang;
int m, n;
int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int t;
	cin >> t;
	int count = 0;
	
	while(t--) {
		cin >> m >> n;
		cin.get();
		string tmp;
		lang1.clear();
		lang2.clear();
		conclang.clear();
		for(int i = 0; i < m; i++) {
			getline(cin, tmp);
			lang1.push_back(tmp);
		}
		for(int j = 0; j < n; j++) {
			getline(cin, tmp);
			lang2.push_back(tmp);
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				string conc = lang1[i] + lang2[j];
				conclang.insert(conc);
			}
		}
		cout << "Case " << ++count << ": " << conclang.size() << endl;
	}
	return 0;
}
