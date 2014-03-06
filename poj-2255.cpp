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
#include <string>
using namespace std;

int leftC[27];
int rightC[27];
string strpre, strin;

int findPos(int r)
{
	int i = 0;
	while(strin[i] != strpre[r]) {
		i++;
	}
	return i;
}

int buildTree(int start1, int end1, int start2, int end2)
{
	if(end1 - start1 == 1) {
		return strpre[start1] - 'A' + 1;
	} else if(end1 <= start1) {
		return 0;
	}
	int pos = findPos(start1);
	int len1 = pos - start2;
	int len2 = end2 - pos - 1;
	int root = strpre[start1] - 'A' + 1;
	leftC[root] = buildTree(start1 + 1, start1 + 1 + len1, start2, pos);
	rightC[root] = buildTree(start1 + len1 + 1, end1, pos + 1, end2);
	return root;
}

void printTree(int root)
{
	if(root == 0) {
		return;
	}
	printTree(leftC[root]);
	printTree(rightC[root]);
	char node= 'A' + root - 1;
	cout << node;
	return;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> strpre >> strin) {
		memset(leftC, 0, sizeof(leftC));
		memset(rightC, 0, sizeof(rightC));
		printTree(buildTree(0, strpre.size(), 0, strpre.size()));
		cout << endl;
	}

	return 0;
}