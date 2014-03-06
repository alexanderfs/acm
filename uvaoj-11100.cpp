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
#include <algorithm>
using namespace std;

int n;
int bagList[10005];
bool flagList[10005];

void proceedBags()
{
	int actual = 0;
	int maxdup = -1;
	int dupcount = 1;
	int val = -1;
	int maxdupval;
	for(int i = 0; i < n; i++) {
		if(bagList[i] != val) {
			if(dupcount > maxdup) {
				maxdup = dupcount;
				maxdupval = val;
			}
			val = bagList[i];
			dupcount = 1;
			actual++;
		} else {
			dupcount++;
		}
	}
	if(dupcount > maxdup) {
		maxdup = dupcount;
		maxdupval = val;
	}
	int maxnum;
	if(maxdup == 1) {
		maxnum = 1;
	} else if(maxdup == n) {
		maxnum = n;
	} else {
		maxnum = n % maxdup == 0 ? n / maxdup : n / maxdup + 1;
	}
	cout << maxdup << endl;
	int nleft = n;
	for(int i = 0; i < maxdup; i++) {
		int val = -1;
		int bagCount = 0;
		for(int j = 0; j < n; j++) {
			if(bagList[j] != val && !flagList[j] && bagList[j] != maxdupval) {
				flagList[j] = true;
				bagCount++;
				val = bagList[j];
				cout << val << " ";
				if(bagCount == maxnum - 1) {
					break;
				}
			}
		}
		cout << maxdupval << endl;
		if(maxdup > 1 && maxdup < n) {
			nleft -= (bagCount + 1);
			if(nleft == 0) {
				break;
			}
			maxnum = nleft / (maxdup - i - 1);
			if(nleft % (maxdup - i - 1) != 0) {
				maxnum++;
			}
			/*maxnum = (n - (bagCount + 1) * (i + 1)) % (maxdup - i - 1) == 0 ?
				(n - (bagCount + 1) * (i + 1)) / (maxdup - i - 1) :
				(n - (bagCount + 1) * (i + 1)) / (maxdup - i - 1) + 1;*/
		}
	}
	
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	cin >> n;
	while(true) {
		for(int i = 0; i < n; i++) {
			cin >> bagList[i];
			flagList[i] = false;
		}
		sort(bagList, bagList + n);
		proceedBags();
		cin >> n;
		if(n == 0) {
			break;
		} else {
			cout << endl;
		}
	}

	return 0;
}