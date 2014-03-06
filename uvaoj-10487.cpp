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
#include <set>
using namespace std;

int n;
int numList[1005];
set<int> sumSet;
int m;
int q;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int cc = 0;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		sumSet.clear();
		for (int i = 0; i < n; i++) {
			cin >> numList[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sumSet.insert(numList[i] + numList[j]);
			}
		}
		cout << "Case " << ++cc << ":" << endl;
		cin >> m;
		while (m--) {
			cin >> q;
			int dist = ~(1 << 31);
			set<int>::iterator iter = sumSet.begin();
			while (iter != sumSet.end() && *iter < q) {
				dist = q - *iter;
				iter++;
			}
			if (iter != sumSet.end() && *iter - q < dist) {
				cout << "Closest sum to " << q << " is " << *iter << "." << endl;
			}
			else {
				cout << "Closest sum to " << q << " is " << (q - dist) << "." << endl;
			}
			
		}
	}

	return 0;
}