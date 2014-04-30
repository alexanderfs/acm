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
#include <vector>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string s;
	while(getline(cin, s)) {
		vector<string> slist;
        int len = s.size();
        string tmp;
        for(int i = 0; i < len; i++) {
            if(s[i] == ' ' && tmp.size() != 0) {
                slist.push_back(tmp);
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
        if(tmp.size() != 0) {
            slist.push_back(tmp);
        }
    
        int vlen = slist.size() - 1;
        if(vlen < 0) {
            cout << endl;
            continue;
        }
        cout << slist[vlen--];
        while(vlen >= 0) {
            cout << " " << slist[vlen--];
        }
        cout << endl;
	}

	return 0;
}