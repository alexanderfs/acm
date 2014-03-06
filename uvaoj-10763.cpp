/*******************************************************************
* Copyright (C) Alex AN
*
* File Name   :
* Author      : Alex AN
* Create      :
* Mail        : alexbupt@gmail.com
* Blog        : http://blog.csdn.net/alexbupt
*
* Description : 一遍读入一遍查找哈希表，找到一个匹配的就加1，并且把
这个哈希项头指针指向0. 最后累加的
数目为输入数一半即可。
还有一个致命的错误。之前做隐式图搜索的时候没有发现过。就是如果需要哈希
的数据列表如果下标从0开始的话，会导致第一个元素插进哈希表也相当于没有
插进去。
这尼玛都能超时。卧槽。 
*
******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXLEN = 500000;
typedef int Cand[2];
Cand cList[MAXLEN + 5];
int hashHead[100000];
int hashNext[MAXLEN + 5];
int n;
int hcount;

int hashValue(Cand &c)
{
	int v = (c[0] + c[1]) % 100000;
	return v;
}

void try_to_insert(int idx)
{
	int v = hashValue(cList[idx]);
	int n = hashHead[v];
	
	while (n) {
		if (cList[n][0] == cList[idx][1] && cList[n][1] == cList[idx][0]) {
			hcount++;
			int p = hashHead[v];
			while (p != n && hashNext[p] != n) {
				p = hashNext[p];
			}
			if (p == n) {
				hashHead[v] = 0;
			}
			else {
				hashNext[p] = hashNext[n];
			}
			return;
		}
	}
	hashNext[idx] = hashHead[v];
	hashHead[v] = idx;

}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			cin >> cList[i][0] >> cList[i][1];
		}
		if (n % 2 == 1) {
			memset(cList, 0, sizeof(cList));
			memset(hashHead, 0, sizeof(hashHead));
			continue;
		}
		hcount = 0;
		for (int i = 1; i <= n; i++) {
			try_to_insert(i);
		}
		if (hcount == n / 2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		memset(cList, 0, sizeof(cList));
		memset(hashHead, 0, sizeof(hashHead));

	}
	return 0;
}