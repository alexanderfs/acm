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
using namespace std;

int lnum, rnum;
int numList[100005];
int primeList[10000];
int primeNum = 0;

bool isPrime(int val)
{
	if(val <= 100000) {
		return numList[val] == 0;
	}
	for(int i = 0; i < primeNum; i++) if(val % primeList[i] == 0){
		return false;
	}
	return true;
}

void buildPrimeList()
{
	numList[0] = numList[1] = 1;
	for(int i = 2; i <= 317; i++) if(numList[i] == 0) {
		for(int j = i * i; j <= 100000; j += i) {
			numList[j] = 1;
		}
	}
	for(int i = 2; i <= 100000; i++) if(numList[i] == 0) {
		primeList[primeNum++] = i;
	}
} 

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	buildPrimeList();
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> lnum >> rnum;
		int i;
		for(i = lnum; i <= rnum && i != (1 << 31); i++) {
			if(isPrime(i)) {
				break;
			}
		}
		if(i == rnum + 1 || i == (1 << 31)) {
			cout << -1 << endl;
			continue;
		}
		int ivalmax = -1;
		int ivalmin = ~(1 << 31);
		int j = i + 1;
		int mina, minb;
		int maxa, maxb;
		bool isFound = false;
		for(; j <= rnum && j != (1 << 31); j++) {
			if(isPrime(j)) {
				isFound = true;
				if(j - i > ivalmax) {
					ivalmax = j - i;
					maxa = i;
					maxb = j;
				}
				if(j - i < ivalmin) {
					ivalmin = j - i;
					mina = i;
					minb = j;
				}
				i = j;
			}
		}
		if(!isFound) {
			cout << -1 << endl;
			continue;
		}
		cout << mina << " " << minb << " " << maxa << " " << maxb << endl;
	}

	return 0;
}