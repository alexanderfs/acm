/*******************************************************************
* Copyright (C) Alex AN
*
* File Name   :
* Author      : Alex AN
* Create      :
* Mail        : alexbupt@gmail.com
* Blog        : http://blog.csdn.net/alexbupt
*
* Description : һ�����һ����ҹ�ϣ���ҵ�һ��ƥ��ľͼ�1�����Ұ�
�����ϣ��ͷָ��ָ��0. ����ۼӵ�
��ĿΪ������һ�뼴�ɡ�
����һ�������Ĵ���֮ǰ����ʽͼ������ʱ��û�з��ֹ������������Ҫ��ϣ
�������б�����±��0��ʼ�Ļ����ᵼ�µ�һ��Ԫ�ز����ϣ��Ҳ�൱��û��
���ȥ��
�����궼�ܳ�ʱ���Բۡ� 
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