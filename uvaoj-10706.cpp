/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 需要注意，问题求的是单个位数。S个数上去以后会出现
 两位三位的数但是它们都是作为流中的一个一个位数计入的。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int calLen(int j)
{
	int sum = 0;
	int p = 1;
	while(j >= p) {
		sum += j - p + 1;
		p = p * 10;
	}
	return sum;
} 

int calD(int k)
{
	int v = 0;
	while(k) {
		v++;
		k = k / 10;
	}
	return v;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	ofstream out("test_output.txt");
	cout.rdbuf(out.rdbuf());
	
	int t, i;
	cin >> t;
	while(t--) {
		cin >> i;
		int j = 1;
		while(i > 0) {
			i -= calLen(j);
			j++;
		}
		j--;
		i += calLen(j);
		int sd = 0;
		int k;
		for(k = 1; k <= j; k++) {
			sd += calD(k);
			if(sd >= i) {
				break;
			}
		}
		if(sd == i) {
			cout << k % 10 << endl;
			continue;
		}
		int len = calD(k);
		sd -= len;
		int tmp = i - sd;
		len = len - tmp;
		while(len > 0) {
			k = k / 10;
			len--;
		}
		cout << k % 10 << endl;
	}

	return 0;
}