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

using namespace std;
char chessBoard[4][4];
int posList[16][2];
int n;
int maxCount;

/*bool checkValid(int x, int y, int c)
{
for(int i = 0; i < n; i++) {
bool hasBlock = false;
for(int j = 0; j < n; j++) {
if(chessBoard[i][j] == 'X') {
hasBlock = true;
}
}
if(!hasBlock) {
for(int k = 0; k < c; k++) {
if(posList[k][0] == x) {
return false;
}
}
}
}

for(int i = 0; i < n; i++) {
bool hasBlock = false;
for(int j = 0; j < n; j++) {
if(chessBoard[j][i] == 'X') {
hasBlock = true;
}
}
if(!hasBlock) {
for(int k = 0; k < c; k++) {
if(posList[k][1] == y) {
return false;
}
}
}
}
return true;
}

bool checkPut(int x, int y, int c)
{
for(int i = 0; i < c; i++) {
if(x == posList[i][0] && y == posList[i][1]) {
return false;
}
}
return true;
}

void dfs(int curr, int count)
{
if(curr == n * n) {
if(count > maxCount) {
maxCount = count;
}
return;
}
for(int i = curr / n; i < n; i++) {
for(int j = curr % n; j < n; j++) {
if(chessBoard[i][j] == '.' && checkValid(i, j, count)) {
posList[count][0] = i;
posList[count][1] = j;
dfs(i * n + j + 1, count + 1);
}
}
}
}*/

bool checkValid(int x, int y, int c)
{
	for (int i = x; i >= 0 && chessBoard[i][y] != 'X'; i--) {
		for (int k = 0; k < c; k++) {
			if (posList[k][0] == i && posList[k][1] == y) {
				return false;
			}
		}
	}
	for (int i = x; i < n && chessBoard[i][y] != 'X'; i++) {
		for (int k = 0; k < c; k++) {
			if (posList[k][0] == i && posList[k][1] == y) {
				return false;
			}
		}
	}

	for (int i = y; i >= 0 && chessBoard[x][i] != 'X'; i--) {
		for (int k = 0; k < c; k++) {
			if (posList[k][0] == x && posList[k][1] == i) {
				return false;
			}
		}
	}
	for (int i = y; i < n && chessBoard[x][i] != 'X'; i++) {
		for (int k = 0; k < c; k++) {
			if (posList[k][0] == x && posList[k][1] == i) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int curr, int count)
{
	
	for (int k = curr; k < n * n; k++) {
		int i = k / n;
		int j = k % n;
		if (chessBoard[i][j] == '.' && checkValid(i, j, count)) {
			posList[count][0] = i;
			posList[count][1] = j;
			if (maxCount < count + 1) {
				maxCount = count + 1;
			}
			dfs(i * n + j + 1, count + 1);
			
		}
	}
	
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> chessBoard[i];
		}
		dfs(0, 0);
		cout << maxCount << endl;
		maxCount = 0;
	}
	return 0;
}