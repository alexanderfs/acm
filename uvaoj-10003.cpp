/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ��һ��RE�����鿪С�ˡ�����ʵ�����Ż���d�д洢����
 �±�ġ������ڶ���TLE��ʹ��memset�������̫��ʱ�ˡ�
 ����������WA���ֶ���λ����ʱ©����һЩԪ�ء� 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int d[1005][1005];
bool v[1005][1005];
int cutList[55];
int len;
int n;

int dp(int start, int end)
{
	if(v[start][end]) {
		return d[start][end];
	}
	
	v[start][end] = true;
	d[start][end] = ~(1 << 31);
	bool isExist = false;
	for(int i = 0; i < n; i++) {
		if(cutList[i] > start && cutList[i] < end) {
			isExist = true;
			int v1 = dp(start, cutList[i]);
			v1 += dp(cutList[i], end);
			if(d[start][end] > v1) {
				d[start][end] = v1;
			}
		}
	}
	if(isExist) {
		d[start][end] += end - start;
	} else {
		d[start][end] = 0;
	}
	//cout << start << ", " << end << ": " << d[start][end] << endl;
	return d[start][end];
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> len) {
		if(!len) {
			break;
		}
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> cutList[i];
		}
		
		cout << "The minimum cutting is " << dp(0, len) << "." << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				d[cutList[i]][cutList[j]] = 0;
				v[cutList[i]][cutList[j]] = false;
			}
		}
		for(int i = 0; i < n; i++) {
			d[0][cutList[i]] = 0;
			d[cutList[i]][len] = 0;
			v[0][cutList[i]] = 0;
			v[cutList[i]][len] = 0;
		}
		d[0][len] = 0;
		v[0][len] = false;
	}

	return 0;
}