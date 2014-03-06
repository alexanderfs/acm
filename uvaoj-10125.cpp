/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 不知道这么做哪里错了，应该是
 （100 -1 -3） 96 
 （50 60 70） 180
 这种问题，按照下面这种搜索方式，会直接返回上面的数据的。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

int numList[1005];
set<int> numSet;
int n;
int d;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		numSet.clear();
		d = 1 << (sizeof(int) * 8 - 1);
		for(int i = 0; i < n; i++) {
			cin >> numList[i];
			numSet.insert(numList[i]);
		}
		sort(numList, numList + n);

		for(int i = n - 1; i >= 0; i--) {
			for(int j = i - 1; j >= 0; j--) {
				for(int k = j - 1; k >= 0; k--) if(i != j && j != k && i != k) {
					int tmp = numList[i] + numList[j] + numList[k];
					if(numSet.count(tmp) && numList[i] != tmp &&
							numList[j] != tmp && numList[k] != tmp) {
						d = tmp;
						goto stop;
					}
				}
			}
		}
		stop:
		/*for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				for(int k = j + 1; k < n; k++) if(i != j && j != k && i != k){
					int tmp = numList[i] + numList[j] + numList[k];
					if(numSet.count(tmp) && tmp > d) {
						d = tmp;
					}
				}
			}
		}*/
		if(d == 1 << (sizeof(int) * 8 - 1)) {
			cout << "no solution" << endl;
		} else {
			cout << d << endl;
		}
	}
	return 0;
}