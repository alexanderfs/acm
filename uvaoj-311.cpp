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
#include <cstring>
using namespace std;

int dataList[7];
int endList[7];

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	ofstream out("test_output.txt");
	cout.rdbuf(out.rdbuf());
	
	while(true) {
		for(int i = 1; i < 7; i++) {
			cin >> dataList[i];
		}
		if(memcmp(dataList, endList, sizeof(dataList)) == 0) {
			break;
		}
		
		int count = 0;
		count = dataList[6] + dataList[5] + dataList[4];
		int num41 = 0;
		if(dataList[4] > 0) {
			if(dataList[2] >= dataList[4] * 5) {
				dataList[2] -= dataList[4] * 5;
			} else {
				num41 = (dataList[4] * 5 - dataList[2]) * 4;
				dataList[2] = 0;
			}
		}
		if(dataList[5] > 0) {
			if(dataList[1] >= dataList[5] * 11) {
				dataList[1] -= dataList[5] * 11;
			} else {
				dataList[1] = 0;
			}
		}
		if(dataList[1] >= num41) {
			dataList[1] -= num41;
		} else {
			dataList[1] = 0;
		}
		
		
		if(dataList[3] > 0) {
			count += (dataList[3] - 1) / 4 + 1;
			int num31 = 0;
			switch(dataList[3] % 4) {
				case 1: {
					if(dataList[2] >= 5) {
						dataList[2] -= 5;
						num31 += 7;
					} else {
						num31 += (5 - dataList[2]) * 4 + 7;
						dataList[2] = 0;
					}
				}
				break;
				case 2: {
					if(dataList[2] >= 3) {
						dataList[2] -= 3;
						num31 += 6;
					} else {
						num31 +=(3 - dataList[2]) * 4 + 6;
						dataList[2] = 0;
					}
				}
				break;
				case 3: {
					if(dataList[2] >= 1) {
						dataList[2] -= 1;
						num31 += 5;
					} else {
						num31 += 9;
						dataList[2] = 0;
					}
				}
				break;
			}
			if(dataList[1] > num31) {
				dataList[1] -= num31;
			} else {
				dataList[1] = 0;
			}
		}
		
		
		int num21 = 0;
		if(dataList[2] > 0) {
			count += (dataList[2] - 1) / 9 + 1;
			num21 = (36 - (dataList[2] % 9) * 4) % 36;
		}
		if(dataList[1] > num21) {
			dataList[1] -= num21;
		} else {
			dataList[1] = 0;
		}
		
		if(dataList[1] > 0) {
			count += (dataList[1] - 1) / 36 + 1;
		}
		
		cout << count << endl;	
		
	}

	return 0;
}