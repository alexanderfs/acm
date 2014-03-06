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
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int n;
int t1, t2;
int numList[20];
char oprList[20];
long long numStack[20];
char oprStack[20];

long long calMax()
{
	int nst = 0;
	int ost = 0;
	int j = 0;
	numStack[nst++] = numList[j++];
	for(int i = 0; i < t2; i++) {
		if(oprList[i] == '*') {
			numStack[nst++] = numList[j++];
		} else if(oprList[i] == '+') {
			numStack[nst - 1] += numList[j++];
		}
	}
	nst--;
	long long val = numStack[nst--];
	while(nst >= 0) {
		val *= numStack[nst--];
	}
	
	return val;
}

long long calMin()
{
	int nst = 0;
	int ost = 0;
	int j = 0;
	numStack[nst++] = numList[j++];
	for(int i = 0; i < t2; i++) {
		if(oprList[i] == '+') {
			numStack[nst++] = numList[j++];
		} else if(oprList[i] == '*') {
			numStack[nst - 1] *= numList[j++];
		}
	}
	nst--;
	long long val = numStack[nst--];
	while(nst >= 0) {
		val += numStack[nst--];
	}
	
	return val;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	cin >> n;
	string expr;
	while(n--) {
		cin >> expr;
		t1 = t2 = 0;
		stringstream ss(expr);
		int num;
		char op;
		ss >> num;
		numList[t1++] = num;
		while(ss >> op >> num) {
			oprList[t2++] = op;
			numList[t1++] = num;
		}
		
		cout << "The maximum and minimum are " << 
			calMax() << " and " << calMin() << "." << endl;
		
	}
	return 0;
}