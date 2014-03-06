/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 没有任何营养的水题。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int cal;
int x[3] = {1, 2, 4};
double T, D, H;

void calH()
{
	//double tmp1 = 6.11 × exp [5417.7530 × ((1/273.16) - (1/(dewpoint+273.16)))]
	double tmp1 = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16))));
	//double tmp2 = (0.5555)× (e - 10.0)
	double tmp2 = 0.5555 * (tmp1 - 10.0);
	H = T + tmp2;
}

void calT()
{
	double tmp1 = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16))));
	double tmp2 = 0.5555 * (tmp1 - 10.0);
	T = H - tmp2;
}

void calD()
{
	double tmp1 = H - T;
	double tmp2 = (tmp1 / 0.5555 + 10.0) / 6.11;
	double tmp3 = log(tmp2) / 5417.7530;
	D = (1 / (1 / 273.16 - tmp3)) - 273.16;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string var;
	while(cin >> var) {
		if(var[0] == 'E') {
			break;
		}
		cal = 0;
		switch(var[0]) {
			case 'T': {
				cal += x[0];
				cin >> T;
				break;
			}
			case 'D': {
				cal += x[1];
				cin >> D;
				break;
			}
			case 'H': {
				cal += x[2];
				cin >> H;
				break;
			}
		}
		cin >> var;
		switch(var[0]) {
			case 'T': {
				cal += x[0];
				cin >> T;
				break;
			}
			case 'D': {
				cal += x[1];
				cin >> D;
				break;
			}
			case 'H': {
				cal += x[2];
				cin >> H;
				break;
			}
		}
		switch(cal) {
			case 3: {
				calH();
				break;
			}
			case 5: {
				calD();
				break;
			}
			case 6: {
				calT();
				break;
			}
		}
		cout << "T " << fixed << setprecision(1) << T << " D " << D << " H " << H << endl;
	}

	return 0;
}