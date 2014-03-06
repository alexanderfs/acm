/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 不是按照从小到大的顺序排列好了再依次加上就完事儿了的。
 需要每次从和以及剩下来的元素中选出最小的两个。 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <queue> 
#include <algorithm>
using namespace std;

int n;
struct pqnum {
	int num;
	pqnum(int n = 0): num(n) {}
};
bool operator< (const pqnum &a, const pqnum &b) 
{
	return a.num >= b.num;
}

priority_queue<pqnum> numList;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n) {
		if(!n) {
			break;
		}
		int tmp;
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			numList.push(pqnum(tmp));
		}
		
		long long csum = 0;
		long long sum;
		while(true) {
			pqnum a = numList.top();
			numList.pop();
			if(numList.empty()) {
				break;
			}
			pqnum b = numList.top();
			numList.pop();
			sum = a.num + b.num;
			csum += sum;
			numList.push(pqnum(sum));
		}
		
		cout << csum << endl;
	}

	return 0;
}