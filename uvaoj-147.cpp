/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ��������ﵽ300ʱ��������int�治������
 ���⣬��һ���ύ����ԭ����ֱ�Ӱ�double��100�������ܿ��ܵõ������Ǳ�
 ��ȷ������1. ��ȷ�������ǳ�100���0.5����ת��int 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int mList[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
int n;
long long d[6005];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	d[0] = 1;
	for(int i = 0; i < 11; i++) {
		for(int j = 1; j <= 6000; j++) if(j >= mList[i]){
			d[j] += d[j - mList[i]];
			//cout << d[i][j] << endl;
		}
	}
	double dv;
	while(cin >> dv) {
		if(abs(dv - 0.00) < 1e-6) {
			break;
		}
		n = static_cast<int>(dv * 100 + 0.5);
		n /= 5;
		cout << setw(6) << fixed << setprecision(2) << dv << setw(17) << d[n] << endl;
	}

	return 0;
}