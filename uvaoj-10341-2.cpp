/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 这是用二分法。还有牛顿法求根以后可以考虑一下 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int p, q, r, s, t, u;
const double dx = 1e-7;

double f(double x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + 
		t * x * x + u;
}

double calResult()
{
	double a = 0.;
	double b = 1.;
	while(b - a > dx) {
		double m = (a + b) / 2;
		if(f(a) * f(m) <= 0) {
			b = m;
		} else {
			a = m;
		}
	}
	
	return (a + b) / 2;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	while(cin >> p >> q >> r >> s >> t >> u) {
		if(f(0) * f(1) > 0) {
			cout << "No solution" << endl;
		} else {
			cout.precision(4);
			cout << fixed << setw(6) << calResult() << endl;
		}
	}

	return 0;
}