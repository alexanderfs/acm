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
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void mergeSort(vector<int> &numbers, vector<int> &idxList, int *tmp, int p, int q) {
        if(q - p <= 1) {
            return;
        }
        int mid = p + (q - p) / 2;
        mergeSort(numbers, idxList, tmp, p, mid);
        mergeSort(numbers, idxList, tmp, mid, q);
        int i1 = p;
        int i2 = mid;
        int i = p;
        while(i1 != mid || i2 != q) {
            if(i2 == q || i1 != mid && numbers[idxList[i1]] < numbers[idxList[i2]]) {
                tmp[i++] = idxList[i1++];
            } else {
                tmp[i++] = idxList[i2++];
            }
        }
        for(int j = p; j < q; j++) {
			idxList[j] = tmp[j];
		}
}

const int vsize = 4;
int vl[vsize] = {0,4,3,0};

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	vector<int> numbers;
	vector<int> idxList;
	srand(time(NULL));
	for(int i = 0; i < vsize; i++) {
		//int val = rand() % 40;
		int val = vl[i];
		numbers.push_back(val);
		idxList.push_back(i);
	}
	
	int *tmpList = new int[numbers.size()];
	mergeSort(numbers, idxList, tmpList, 0, vsize);
	int	target = 0;
	for(int i = 0; i < vsize; i++) {
            int v = target - numbers[idxList[i]];
            int low = 0;
            int up = vsize - 1;
            int mid;
            while(low <= up) {
                mid = low + (up - low) / 2;
                if(v == numbers[idxList[mid]]) {
                    vector<int> re;
                    int r1 = idxList[i];
                    int r2 = idxList[mid];
                    if(r1 == r2) {
                        r2 = numbers[idxList[mid-1]] == numbers[idxList[i]] ? idxList[mid - 1] : idxList[mid + 1];
                    }
                    if(r1 > r2) {
                        r1 = r1 ^ r2;
                        r2 = r1 ^ r2;
                        r1 = r1 ^ r2;
                    }
                    cout << r1 + 1 << ", " << r2 + 1 << endl;
                    return 0;
                } else if(v > numbers[idxList[mid]]) {
                    low = mid + 1;
                } else {
                    up = mid - 1;
                }
            }
 	}
    delete [] tmpList;    
	return 0;
}