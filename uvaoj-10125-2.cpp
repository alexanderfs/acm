/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 哈希解决。以后要锻炼分析问题的能力 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

#define TABLE_SIZE 1005

int numList[TABLE_SIZE];
struct TRI {
	int sum;
	int a;
	int b;
};

const int HASH_SIZE = TABLE_SIZE * TABLE_SIZE;
TRI sumList[HASH_SIZE];
int hashHead[HASH_SIZE + 5];
int hashNext[HASH_SIZE];
int n;
int rear;

void hashInit()
{
	memset(hashHead, 0, sizeof(hashHead));
}

int hashValue(int s)
{
	int val = s % HASH_SIZE;
	if(val < 0) {
		val = -val;
	}
	return val;
}

void hashInsert(int idx)
{
	int val = hashValue(sumList[idx].sum);
	hashNext[idx] = hashHead[val];
	hashHead[val] = idx;
}

bool isExist(int s, int i, int j)
{
	int val = hashValue(s);
	int n = hashHead[val];
	while(n) {
		if(sumList[n].sum == s && sumList[n].a != numList[i] &&
			sumList[n].a != numList[j] && sumList[n].b != numList[i] &&
			sumList[n].b != numList[j]) {
			return true;	
		}
		n = hashNext[n];
	}
	return false;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		rear = 0;
		hashInit();
		for(int i = 0; i < n; i++) {
			cin >> numList[i];
		}
		sort(numList, numList + n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) if(i != j) {
				int s = numList[i] + numList[j];
				sumList[rear].sum = s;
				sumList[rear].a = numList[i];
				sumList[rear].b = numList[j];
				hashInsert(rear);
				rear++;
			}
		}
		bool isFound = false;
		for(int i = n - 1; i >= 0 && !isFound; i--) {
			for(int j = n - 1; j >= 0 && !isFound; j--) if(i != j) {
				int sub = numList[i] - numList[j];
				if(isExist(sub, i, j)) {
					cout << numList[i] << endl;
					isFound = true;
					break;
				}
			}
		}
		if(!isFound) {
			cout << "no solution" << endl;
		}
		
	}
	return 0;
}