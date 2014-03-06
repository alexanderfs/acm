/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 整个思路都是错的。还是得看题解才行啊。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int n;
vector<string> nList;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		nList.clear();
		string tmp;
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			nList.push_back(tmp);
		}
		sort(nList.rbegin(), nList.rend());//降序排序
		int front = 0;
		int rear = 1;
		string maxStr;
		maxStr = accumulate(nList.begin(), nList.end(), string(""));
		string numStr;
		while(front < nList.size()) {
			while(rear < nList.size() && nList[front] != nList[rear] &&
				nList[front][0] == nList[rear][0]) {
				rear++;	
			}
			if(rear - front == 1) {
				front = rear;
				rear++;
				continue;
			}
			sort(nList.begin() + front, nList.begin() + rear);
			while(next_permutation(nList.begin() + front, nList.begin() + rear)) {
				numStr = accumulate(nList.begin(), nList.end(), string(""));
				if(numStr > maxStr) {
					maxStr = numStr;
				}
			}
			front = rear;
			rear++;
		} 
		cout << maxStr << endl;
	}
	return 0;
}