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

int v[1000];
int primList[1000];
int len;
int n;

void buildPrim()
{
	v[0] = v[1] = 1;
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * 2; j <= 1000; j += i) {
			v[j] = 1;
		} 
	}
	int i, j;
	for(i = 0, j = 0; j <= 1000; j++) if(v[j] == 0) {
		primList[i++] = j;
	}
	len = i;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	buildPrim();
	
	while(cin >> n) {
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
		int count = 0;
		for(int i = 0; i < len; i++) {
			int tmp = 0;
			while(n % primList[i] == 0) {
				tmp++;
				n /= primList[i];
			}
			if(tmp > 1) {
				count += (primList[i] + tmp);
			} else if(tmp == 1) {
				count += primList[i];
			}
			if(n == 1) {
				break;
			}
		}
		
		cout << count << endl;
	}
	
	return 0;
}