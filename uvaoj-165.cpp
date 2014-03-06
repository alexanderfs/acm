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
#include <iomanip>
#include <cstring>
using namespace std;

int h, k;
int clist[10];
int mlist[10];
int ck;
int cmax;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> h >> k) {
		if(!h && !k) {
			break;
		}
		for(int i = 0; i < k && h != 1; i++) {
			ck = i + 1;//目前的面值种类数
			if(i == 0) {
				clist[i] = mlist[i] = 1;
				cmax = h;
			} else {
				int tmax = cmax + 1;
				memcpy(clist, mlist, sizeof(mlist));
				for(int j = clist[i - 1] + 1; j < cmax + 2; j++) {
					clist[i] = j;
					int rmax = cmax + 1;
					while(true) {
						int t = rmax;
						for(int k1 = 0, l = i; k1 < h && t; k1++) {
							while(l >= 0 && clist[l] > t) {
								l--;
							}
							if(l < 0) {
								l = 0;
							}
							t -= clist[l];
						}
						if(t == 0) {
							rmax++;
						} else {
							rmax--;
							break;
						}
					}
					if(rmax > tmax) {
						tmax = rmax;
						memcpy(mlist, clist, sizeof(clist));
					} else {
						continue;
					}
				}
				cmax = tmax;
			}
		}
		if(h == 1) {
			for(int i = 0; i < k; i++) {
				cout << setw(3) << i + 1;
			}
			cout << " ->" << setw(3) << "1" << endl;
		} else {
			for(int i = 0; i < k; i++) {
				cout << setw(3) << mlist[i];
			}
			cout << " ->" << setw(3) << cmax << endl;
		}
		
	}
	return 0;
}