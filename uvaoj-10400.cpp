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

const int OFFSET = 32000;
bool visitList[100][OFFSET * 2 + 5];
int numList[105];
int opList[105];
char opmap[4] = {'+', '-', '*', '/'};
int n, tn;

void printResult()
{
	 cout << numList[0];
	 for(int i = 1; i < n; i++) {
	 	cout << opmap[opList[i]] << numList[i];
	 }
	 cout << '=' << tn << endl;
}

bool dfs(int cv, int idx) 
{
	if(idx == n) 
	{
		if(cv == tn) 
		{
			printResult();
			return true;
		} else {
			return false;
		}
	}
	
	bool res = false;;
	for(int i = 0; i < 4; i++) 
	{
		switch(i) 
		{
		case 0:
		{
			int val = cv + numList[idx];
			if(val >= -32000 && val <= 32000 && !visitList[idx][val + OFFSET])
			{
				opList[idx] = 0;
				visitList[idx][val + OFFSET] = true;
				res = dfs(val, idx + 1);
				if(res) {
					return true;
				}
			}
		}
		break;
		case 1:
		{
			int val = cv - numList[idx];
			if(val >= -32000 && val <= 32000 && !visitList[idx][val + OFFSET])
			{
				opList[idx] = 1;
				visitList[idx][val + OFFSET] = true;
				res = dfs(val, idx + 1);
				if(res) {
					return true;
				}
			}
		}
		break;
		case 2:
		{
			int val = cv * numList[idx];
			if(val > -32000 && val < 32000 && !visitList[idx][val + OFFSET])
			{
				opList[idx] = 2;
				visitList[idx][val + OFFSET] = true;
				res = dfs(val, idx + 1);
				if(res) {
					return true;
				}
			}
		}
		break;
		case 3:
		{
			if(numList[idx] != 0 && cv % numList[idx] == 0)
			{
				int val = cv / numList[idx];
				if(val > -32000 && val < 32000 && !visitList[idx][val + OFFSET])
				{
					opList[idx] = 3;
					visitList[idx][val + OFFSET] = true;
					res = dfs(val, idx + 1);
					if(res) {
						return true;
					}
				}	
			}
			
		}
		break;
		}
	}
	
	return false;
}

int main() 
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int tcn;
	cin >> tcn;
	while(tcn--) 
	{
		cin >> n;
		for(int i = 0; i < n; i++) 
		{
			cin >> numList[i];
		}
		cin >> tn;
		if(!dfs(numList[0], 1)) {
			cout << "NO EXPRESSION" << endl;
		}
		memset(visitList, false, sizeof(visitList));
	}

	return 0;
}