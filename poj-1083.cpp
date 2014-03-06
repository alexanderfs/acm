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

using namespace std;

int moveList[205][2];
int n;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> moveList[i][0];
			moveList[i][0] = (moveList[i][0] + 1) / 2;
			cin >> moveList[i][1];
			moveList[i][1] = (moveList[i][1] + 1) / 2;
		}
		int maxcount = 0;
		for(int i = 1; i <= 200; i++) {
			int tmp = 0;
			for(int j = 0; j < n; j++) {
				if(i >= moveList[j][0] && i <= moveList[j][1] ||
					i >= moveList[j][1] && i <= moveList[j][0]) {
					tmp++;
				}
			}
			if(tmp > maxcount) {
				maxcount = tmp;
			}
		}
		cout << maxcount * 10 << endl;
	}

	return 0;
}