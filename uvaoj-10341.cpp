/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 显然不对了啊，首先这样输出小数点后的位数就不能保证是
 对的。但是精确结果现在还是不知道要怎么才能得出来。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	int p, q, r, s, t, u;
	
	double sum;
	
	while(cin >> p >> q >> r >> s >> t >> u) {
		bool isFound = false;
		for(int i = 0; i < 10001; i++) {
			double x = i / 10000.0;
			sum = 0;
			if(p) {
				sum += p * exp(-x);
			}
			if(q) {
				sum += q * sin(x);
			}
			if(r) {
				sum += r * cos(x);
			}
			if(s) {
				sum += s * tan(x);
			}
			if(t) {
				sum += t * x * x;
			}
			if(u) {
				sum += u;
			}
			if(sum < 0.0001) {
				cout << "0." << i << endl;
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			cout << "No solution" << endl;
		}
	}

	return 0;
}