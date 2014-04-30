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

double ox1, oy1, ox2, oy2;
double dx, dy;
double nx1, ny1, nx2, ny2;
double cx1, cy1;
double dis;
const double PI = 3.141592653;
const double DX = 0.00001;
double aval, bval;


void getDis()
{
	double dx = ox2 - ox1;
	double dy = oy2 - oy1;
	dis = sqrt(dx * dx + dy * dy) / 2;
	
	aval = (fabs(dy) * dis) / sqrt(dy * dy + dx * dx);
	bval = aval * dx / dy;
	
	cx1 = (ox1 + ox2) / 2;
	cy1 = (oy1 + oy2) / 2;

	nx1 = cx1 + bval;
	nx2 = cx1 - bval;
	ny2 = cy1 + aval;
	ny1 = cy1 - aval;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> ox1 >> oy1 >> ox2 >> oy2;
		if(fabs(ox1 - ox2) <= DX) {
			dis = fabs((oy1 - oy2) / 2);
			nx1 = ox1 - dis;
			nx2 = ox1 + dis;
			ny1 = ny2 = (oy1 + oy2) / 2;
			cout << fixed << setprecision(2) << nx1 << " " << ny1 << endl;
			cout << fixed << setprecision(2) << nx2 << " " << ny2 << endl;
		} else if(fabs(oy1 - oy2) <= DX) {
			dis = fabs((ox1 - ox2) / 2);
			ny1 = oy1 - dis;
			ny2 = oy2 + dis;
			nx1 = nx2 = (ox1 + ox2) / 2;
			cout << fixed << setprecision(2) << nx1 << " " << ny1 << endl;
			cout << fixed << setprecision(2) << nx2 << " " << ny2 << endl;
		} else {
			getDis();
			if(nx1 > nx2 || (fabs(nx1 - nx2) <= DX && ny1 > ny2)) {
				cout << fixed << setprecision(2) << nx2 << " " << ny2 << endl;
				cout << fixed << setprecision(2) << nx1 << " " << ny1 << endl;
			} else {
				cout << fixed << setprecision(2) << nx1 << " " << ny1 << endl;
				cout << fixed << setprecision(2) << nx2 << " " << ny2 << endl;
			}
		}
	}

	return 0;
}