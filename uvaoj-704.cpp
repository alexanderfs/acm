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
using namespace std;

#define MAXSIZE 1000000
typedef int Config[24];
Config sq[MAXSIZE];
Config finalConfig = 
	{0, 3, 4, 3, 0, 5, 6, 5, 0, 1, 2, 1, 0, 7, 8, 7, 0, 9, 10, 9, 0, 1, 2, 1};
int front, rear;
int prevStep[MAXSIZE];
int moveRecord[MAXSIZE];
int hashHead[10000];
int hashNext[MAXSIZE];

int calHash(Config &c)
{
	int val = 0;
	for(int i = 0; i < 9; i++) if(c[i] != 0) {
		val = val * 10 + c[i];
	}
	return val % 10000;
}

bool isExist(int idx)
{
	int hv = calHash(sq[idx]);
	int nodeidx = hashHead[hv];
	while(nodeidx) {
		if(memcmp(sq[idx], sq[nodeidx], sizeof(sq[idx])) == 0) {
			return true;
		}
		nodeidx = hashNext[nodeidx];
	}
	hashNext[idx] = hashHead[hv];
	hashHead[hv] = idx;
	return false;
}
	
int bfs()
{
	memset(hashHead, 0, sizeof(hashHead));
	front = rear = 0;
	Config &firstNode = sq[front];
	for(int i = 0; i < 24; i++) {
		cin >> firstNode[i];
	}
	rear++;
	if(memcmp(firstNode, finalConfig, sizeof(finalConfig)) == 0) {
		return 1;
	}
	while(front < rear) {	
		Config &firstNode = sq[front];
		for(int i = 0; i < 4; i++) {
			Config &lastNode = sq[rear];
			memcpy(lastNode, firstNode, sizeof(firstNode));
			switch(i) {
				case 0: {
					int t1 = lastNode[10];
					int t2 = lastNode[11];
					memmove(lastNode + 2, lastNode, sizeof(int) * 10);
					lastNode[0] = t1;
					lastNode[1] = t2;
					lastNode[21] = lastNode[9];
					lastNode[22] = lastNode[10];
					lastNode[23] = lastNode[11];
				}	
				break;
				
				case 1: {
					int t1 = lastNode[12];
					int t2 = lastNode[13];
					memmove(lastNode + 12, lastNode + 14, sizeof(int) * 10);
					lastNode[22] = t1;
					lastNode[23] = t2;
					lastNode[9] = lastNode[21];
					lastNode[10] = lastNode[22];
					lastNode[11] = lastNode[23];
				}
				break;
				
				case 2: {
					int t1 = lastNode[0];
					int t2 = lastNode[1];
					memmove(lastNode, lastNode + 2, sizeof(int) * 10);
					lastNode[10] = t1;
					lastNode[11] = t2;
					lastNode[21] = lastNode[9];
					lastNode[22] = lastNode[10];
					lastNode[23] = lastNode[11];
				}
				break;
				
				case 3: {
					int t1 = lastNode[22];
					int t2 = lastNode[23];
					memmove(lastNode + 14, lastNode + 12, sizeof(int) * 10);
					lastNode[12] = t1;
					lastNode[13] = t2;
					lastNode[9] = lastNode[21];
					lastNode[10] = lastNode[22];
					lastNode[11] = lastNode[23];
				}
				break;
			}
			if(isExist(rear) == false) {
				if(memcmp(lastNode, finalConfig, sizeof(finalConfig)) == 0) {
					prevStep[rear] = front;
					moveRecord[rear] = i + 1;
					return 0;
				} else {
					prevStep[rear] = front;
					moveRecord[rear] = i + 1;
					if(rear < MAXSIZE - 1) {
						rear++;
					}
				}
			}
		}
		front++;
	}
	cout << front << ", " << rear << endl;
	return 2;
}


void printStep()
{
	int stepStack[20];
	int st = 0;
	int idx = rear;
	while(idx) {
		stepStack[st++] = idx;
		idx = prevStep[idx];
	}
	st--;
	while(st >= 0) {
		cout << moveRecord[st--];
	}
	cout << endl;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		int result = bfs();
		if(result == 0) {
			printStep();
		} else if(result == 1){
			cout << "PUZZLE ALREADY SOLVED" << endl;
		} else {
			cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
		}
	}

	return 0;
}