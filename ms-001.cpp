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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

int countList[150];
int zeroList[150];

void printResult(void) {
	while(true) {
		for(int i = 0; i < 150; i++) if(countList[i] > 0){
			printf("%c", i);
			countList[i]--;
		}
		if(memcmp(countList, zeroList, sizeof(countList)) == 0) {
			break;
		}
	}
	printf("\n");
}

int main() {
	freopen("test_input.txt", "r", stdin);
	bool isFinish = false;
	bool isValid = true;
	while(!isFinish) {
		char currc;
		while(true) {
			if(scanf("%c", &currc) == 1) {
				if(isdigit(currc) || islower(currc)) {
					countList[currc]++;
				} else if(currc == '\n') {
					break;
				} else {
					isValid = false;
					break;
				}
			} else {
				isFinish = true;
				break;
			}
		}
		if(isValid) {
			printResult();
		} else {
			while((scanf("%c", &currc) == 1) && (currc != '\n')) {
				;
			}
			if(currc != '\n') {
				isFinish = true;
			}
			printf("<invalid input string>\n");
			isValid = true;
		}	
		memset(countList, 0, sizeof(countList));
	}

	return 0;
}