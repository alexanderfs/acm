/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : �����ϵķ�������һ�� 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string strcontent;

void reversestring(int start, int end, string &str) {
	for(int i = start, j = end; i < j; i++, j--) {
		str[i] = str[i] ^ str[j];
		str[j] = str[i] ^ str[j];
		str[i] = str[i] ^ str[j];
	}
}

//�ҵ����ʵĵ�һ���ַ� 
int getnextstart(int pos, int len) {
	while(pos < len && isblank(strcontent[pos])) {
		pos++;
	}
	return pos;
}

//�ҵ����ʵ����һ���ַ�����һ���ַ� 
int getnextend(int pos, int len) {
	while(pos < len && !isblank(strcontent[pos])) {
		pos++;
	}
	return pos;
}

int main() {
	//freopen("test_input.txt", "r", stdin);
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(getline(cin, strcontent)) {
		int len = strcontent.size();
		reversestring(0, len - 1, strcontent);
		int pos1 = 0;
		int pos2 = 0;
		while(true) {
			pos1 = getnextstart(pos2, len);
			if(pos1 >= len) {
				break;
			}
			pos2 = getnextend(pos1, len);
			reversestring(pos1, pos2 - 1, strcontent);
		}
		cout << strcontent << endl;
	}

	return 0;
}