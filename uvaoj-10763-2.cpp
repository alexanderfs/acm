/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 又得看题解，题解有时候也不靠谱。各种不靠谱。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN = 500000;
int oList[MAXLEN + 5];
int nList[MAXLEN + 5];
int n;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(!n) {
			break;
		}
		memset(oList, 0, sizeof(oList));
		memset(nList, 0, sizeof(nList));
		for(int i = 0; i < n; i++) {
			cin >> oList[i] >> nList[i];
		}
		sort(oList, oList + n);
		sort(nList, nList + n);
		if(memcmp(oList, nList, sizeof(int) * n) == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	

	return 0;
}