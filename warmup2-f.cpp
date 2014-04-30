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
#include <cstdlib>
using namespace std;

char sstr[1000005];
char tstr[1000005];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> sstr;
		cin >> tstr;
		int lens = strlen(sstr);
		int lent = strlen(tstr);
		char *start = strstr(sstr, tstr);
		char *end = start + lent;
		int lenmax = 0;
		int len = lent;
		
		while(start != NULL && start < sstr + lens) {
			bool isFound = false;
			int i;
			for(i = lent - 1; i > 0; i--) if(sstr + lens - (start + i) >= lent){
				if(strncmp(start + i, tstr, sizeof(char) * lent) == 0) {
					len += i;
					isFound = true;
					break;
				}
			}
			if(isFound) {
				start += i;
			} else {
				if(lenmax < len) {
					lenmax = len;
				}
				start = strstr(start + 1, tstr);
				if(start == NULL) {
					break;
				} else {
					len = lent;
				}
			}
		}
		cout << lenmax << endl;
	}

	return 0;
}