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
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;


int cpts[8][2];
int cptList[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int minList[8];
int cptn;
double dist = 1000000000;

double calDist(int a, int b)
{
	return sqrt((cpts[a][0] - cpts[b][0]) * (cpts[a][0] - cpts[b][0]) +
		(cpts[a][1] - cpts[b][1]) * (cpts[a][1] - cpts[b][1]));
}

void dfs(int n, double cdist)
{
	if(n == cptn) {
		if(dist > cdist) {
			dist = cdist;
			memcpy(minList, cptList, sizeof(cptList));
		}
		return;
	}
	
	for(int i = 0; i < cptn; i++) {
		int isFound = false;
		for(int j = 0; j < n; j++) {
			if(cptList[j] == i) {
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			if(n == 0) {
				cptList[n] = i;
				dfs(n + 1, 0);
			} else {
				double ndist = cdist + calDist(cptList[n - 1], i);
				if(dist < ndist) {
					continue;
				} else {
					cptList[n] = i;
					dfs(n + 1, ndist);
				}
			}
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 1;
	while(cin >> cptn) {
		if(cptn == 0) {
			break;
		}
		for(int i = 0; i < cptn; i++) {
			cin >> cpts[i][0] >> cpts[i][1];
		}
		dist = 1000000000;
		dfs(0, 0);
		
		cout << "**********************************************************" << endl;
		cout << "Network #" << count++ << endl;
		for(int i = 0; i < cptn - 1; i++) {
			cout << fixed << setprecision(2) << "Cable requirement to connect (" << cpts[minList[i]][0] << "," <<
				cpts[minList[i]][1] << ") to (" << cpts[minList[i + 1]][0] << "," <<
				cpts[minList[i + 1]][1] << ") is " << calDist(minList[i], minList[i + 1]) + 16. <<
				" feet." << endl;
		}
		cout << fixed << setprecision(2) << "Number of feet of cable required is " << dist + static_cast<double>(16 * (cptn - 1)) << "." << endl;
	}
	return 0;
}