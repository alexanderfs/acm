/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 应该都是很简单的思想。为什么要想这么久 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct segpair {
	int l;
	int r;
	segpair(int a = 0, int b = 0): l(a), r(b) {
		
	}
	//friend bool operator< (const segpair &s1, const segpair &s2);
};

bool operator< (const segpair &s1, const segpair &s2) 
{
	if(s1.l < s2.l) {
		return true;
	}
	if(s1.l == s2.l && s1.r < s2.r) {
		return true;
	} else {
		return false;
	}
}

vector<segpair> segList;
vector<int> segStack;
int sst;
int m;
int s;

int getUpperBound(int val)
{
	int s = 0;
	int e = segList.size();
	while(s < e) {
		int m = s + (e - s) / 2;
		if(segList[m].l <= val) {
			s = m + 1;
		} else {
			e = m;
		}
	}
	return e;
}

int getLowerBound(int val)
{
	for(int i = 0; i < segList.size(); i++) {
		if(segList[i].l > val) {
			return i;
		}
	}
}

int proceedList(int val)
{
	int idx1 = getUpperBound(val);//找出左值大于val的第一个数作为上界 
	//int idx2 = getLowerBound(val);//找出右值小于val的最后一个数作为下界之前一个元素
	
	int maxLen = 0;
	int maxIdx;
	bool isDone = false;
	for(int i = 0; i < idx1; i++) {
		if(segList[i].r - val > maxLen) {
			maxLen = segList[i].r - val;
			maxIdx = i;
			if(segList[i].r >= m) {
				isDone = true;
			}
		}
	} 
	if(maxLen != 0) {
		segStack.push_back(maxIdx);
		if(!isDone) {
			return proceedList(segList[maxIdx].r);
		} else {
			return 0;
		}
	} else {
		return 1; //没有符合要求的段 
	}
	
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	int tcn;
	cin >> tcn;
	while(tcn--) {
		cin >> m;
		s = 0;
		segList.clear();
		segStack.clear();
		sst = 0;
		int a, b;
		while(cin >> a >> b) {
			if(!a && !b) {
				break;
			}
			segList.push_back(segpair(a, b));
		}
		sort(segList.begin(), segList.end());
		int result = proceedList(0);
		if(!result) {
			cout << segStack.size() << endl;
			for(int i = 0; i < segStack.size(); i++) {
				cout << segList[segStack[i]].l << " " << segList[segStack[i]].r << endl;
			}
		} else {
			cout << "0" << endl;
		}
		if(tcn != 0) {
			cout << endl;
		}
	}

	return 0;
}