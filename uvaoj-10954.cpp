/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ���ǰ��մ�С�����˳�����к��������μ��Ͼ����¶��˵ġ�
 ��Ҫÿ�δӺ��Լ�ʣ������Ԫ����ѡ����С�������� 
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