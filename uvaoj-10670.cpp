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
#include <algorithm>
using namespace std;

char agList[105][20];
int aList[105];
int bList[105];
int idxList[105];
int costList[105];
int n, m, l;

bool myComp(int a, int b)
{
	if(costList[a] == costList[b]) {
		string str1(agList[a]);
		string str2(agList[b]);
		return str1 < str2;
	}
	return costList[a] < costList[b];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	int count = 0;
	cin >> tcn;
	while (tcn--) {
		cin >> n >> m >> l;
		cin.get();
		for (int i = 0; i < l; i++) {
			int j = 0;
			while ((cin >> agList[i][j]) && (agList[i][j] != ':')) {
				j++;
			}
			agList[i][j] = '\0';
			cin >> aList[i];
			cin.get();
			cin >> bList[i];
			cin.get();
			idxList[i] = i;
		}
		for (int i = 0; i < l; i++) {
			int start = n;
			int target = m;
			costList[i] = 0;
			while (start > target) {
				if (start / 2 >= target) {
					if (bList[i] <= (aList[i] * (start - start / 2))) {
						costList[i] += bList[i];	
					}
					else {
						costList[i] += (start - start / 2) * aList[i];
					}
					start >>= 1;
				}
				else {
					costList[i] += aList[i];
					start -= 1;
				}
			}
		}
		sort(idxList, idxList + l, myComp);
		cout << "Case " << ++count << endl;
		for (int i = 0; i < l; i++) {
			cout << agList[idxList[i]] << " " << costList[idxList[i]] << endl;
		}
	}

	return 0;
}