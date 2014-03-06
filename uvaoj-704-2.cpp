/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 之前那个数组上限没有设判断，超了直接就把接下来的全局变量给覆盖了所以
 会出现问题。另外，还是不知道怎么判断状态数量，以至于无法开出适当大小的数组。对于
 状态量太多导致单向广搜无法使用的问题更是无从下手了。这次进行双向广搜。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAXSIZE 1000000
#define HASHSIZE 10000
typedef int Config[24];
Config sqf[MAXSIZE];
Config sqb[MAXSIZE];
Config finalConfig = 
	{0, 3, 4, 3, 0, 5, 6, 5, 0, 1, 2, 1, 0, 7, 8, 7, 0, 9, 10, 9, 0, 1, 2, 1};
int frontf, rearf;
int frontb, rearb;
int fatherf[MAXSIZE];
int fatherb[MAXSIZE];
int stepf[MAXSIZE];
int stepb[MAXSIZE];
int layerf[MAXSIZE];
int layerb[MAXSIZE];

int hashheadf[HASHSIZE];
int hashheadb[HASHSIZE];
int hashnextf[MAXSIZE];
int hashnextb[MAXSIZE];

int statusCode;

int calHash(Config &c)
{
	int val = 0;
	for(int i = 0; i < 9; i++) if(c[i] != 0) {
		val = val * 10 + c[i];
	}
	return val % HASHSIZE;
}

bool isExistB(int idx)
{
	int hv = calHash(sqb[idx]);
	int nodeidx = hashheadb[hv];
	while(nodeidx) {
		if(memcmp(sqb[idx], sqb[nodeidx], sizeof(sqb[idx])) == 0) {
			return true;
		}
		nodeidx = hashnextb[nodeidx];
	}
	hashnextb[idx] = hashheadb[hv];
	hashheadb[hv] = idx;
	return false;
}

int isExistB(Config &c)
{
	int hv = calHash(c);
	int nodeidx = hashheadb[hv];
	while(nodeidx) {
		if(memcmp(c, sqb[nodeidx], sizeof(c)) == 0) {
			return nodeidx;
		}
		nodeidx = hashnextb[nodeidx];
	}
	
	return -1;
}

bool isExistF(int idx)
{
	int hv = calHash(sqf[idx]);
	int nodeidx = hashheadf[hv];
	while(nodeidx) {
		if(memcmp(sqf[idx], sqf[nodeidx], sizeof(sqf[idx])) == 0) {
			return true;
		}
		nodeidx = hashnextf[nodeidx];
	}
	hashnextf[idx] = hashheadf[hv];
	hashheadf[hv] = idx;
	return false;
}

void bfsBack()
{
	
	frontb = rearb = 0;
	Config &firstNode = sqb[frontb];
	memcpy(firstNode, finalConfig, sizeof(finalConfig));
	isExistB(frontb);
	rearb++;
	layerb[frontb] = 0;
	while(frontb < rearb) {
		if(layerb[frontb] >= 8) {
			frontb++;
			continue;
		}
		Config &firstNode = sqb[frontb];
		for(int i = 0; i < 4; i++) {
			Config &lastNode = sqb[rearb];
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
			if(isExistB(rearb) == false) {
				fatherb[rearb] = frontb;
				//这里frontb状态是由rearb状态经过switch转换后的操作产生的
				//正常是由frontb状态通过i操作产生rearb状态 
				switch(i) {
					case 0:
						stepb[rearb] = 3;
						break;
					case 1:
						stepb[rearb] = 4;
						break;
					case 2:
						stepb[rearb] = 1;
						break;
					case 3:
						stepb[rearb] = 2;
						break;
					
				}
				layerb[rearb] = layerb[frontb] + 1;
				if(rearb < MAXSIZE - 1) {
					rearb++;
				}
			}
		}
		frontb++;
	}
}

//返回0表示直接找到
//返回-1表示没找到
//返回-2表示直接匹配 
//返回其他数表示需要在逆向遍历中打印路径
int bfsForward()
{
	memset(hashheadf, 0, sizeof(hashheadf));
	frontf = rearf = 0;
	Config &firstNode = sqf[frontf];
	for(int i = 0; i < 24; i++) {
		cin >> firstNode[i];
	}
	
	if(memcmp(firstNode, finalConfig, sizeof(finalConfig)) == 0) {
		return -2;
	}
	int pos = -1;
	if((pos = isExistB(firstNode)) != -1) {
		return pos;
	}
	rearf++;
	isExistF(frontf);
	while(frontf < rearf) {	
		if(layerf[frontf] > 8) {
			frontf++;
			continue;
		}
		Config &firstNode = sqf[frontf];
		for(int i = 0; i < 4; i++) {
			Config &lastNode = sqf[rearf];
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
			if(isExistF(rearf) == false) {
				int pos = -1;
				if(memcmp(lastNode, finalConfig, sizeof(finalConfig)) == 0) {
					fatherf[rearf] = frontf;
					stepf[rearf] = i + 1;
					//这里的step就表示rearf的状态是由frontf状态经由i变换得来 
					return 0;
				} else if((pos = isExistB(lastNode)) != -1){
					fatherf[rearf] = frontf;
					stepf[rearf] = i + 1;
					return pos;
					//这里的pos表示找到的B深搜的队列下标 
				} else if(pos == -1) {
					fatherf[rearf] = frontf;
					stepf[rearf] = i + 1;
					layerf[rearf] = layerf[frontf] + 1;
					if(rearf < MAXSIZE - 1) {
						rearf++;
					}
				}
			}
		}
		frontf++;
	}
	
	return -1;
} 

void printStep()
{
	int printSeq[20] = {0};
	int idx = 0;
	int printStack[20] = {0};
	int st = 0;
	int val = rearf;
	while(val) {
		printStack[st++] = val;
		val = fatherf[val];
	}
	st--;
	while(st >= 0) {
		cout << stepf[printStack[st--]];
		//printSeq[idx++] = stepf[printStack[st--]];
	}
	
	if(statusCode == 0) {
		cout << endl;
		return;
	} 
	val = statusCode;
	while(val) {
		cout << stepb[val];
		val = fatherb[val];
	}
	cout << endl;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	ofstream out("test_output.txt");
	cout.rdbuf(out.rdbuf());
	bfsBack();
	int count;
	cin >> count;
	while(count--) {
		statusCode = bfsForward();
		if(statusCode == -2) {
			cout << "PUZZLE ALREADY SOLVED" << endl;
		} else if(statusCode == -1) {
			cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
		} else {
			printStep();
		}
	}
	return 0;
}
