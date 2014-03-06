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
#include <cmath>
#include <iomanip>
using namespace std;

double pointList[10005][2];
int n;

double calDis(int a, int b)
{
	double ax = pointList[a][0];
	double bx = pointList[b][0];
	double ay = pointList[a][1];
	double by = pointList[b][1];
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			 cin >> pointList[i][0] >> pointList[i][1];
		}
		double minDis = ~(1 << 31);
		minDis *= 2;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				double currDis = calDis(i, j);
				if(minDis > currDis) {
					minDis = currDis;
				}
			}
		}
		double dis = sqrt(minDis);
		if(dis >= 10000) {
			cout << "INFINITY" << endl;
		} else {
			cout << fixed << setprecision(4) << dis << endl;
		}
	}

	return 0;
}