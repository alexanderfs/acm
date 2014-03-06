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

bool primList[1000005];
int a, d, n;
void buildPrimList()
{
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * i; j < 1000000; j += i) {
			primList[j] = true;
		}
	}
	primList[0] = primList[1] = true;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	buildPrimList();
	while(cin >> a >> d >> n) {
		if(!a && !d && !n) {
			break;
		}
		int ncount = 0;
		int i = 0;
		while(ncount < n) {
			if(primList[a + d * i] == false) {
				ncount++;
			}
			i++;
		}
		cout << a + d * (i - 1) << endl;
	}
	return 0;
}