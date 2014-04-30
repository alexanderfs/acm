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
#include <map>
using namespace std;

struct BiLinkNode {
    int val;
    BiLinkNode *prev;
    BiLinkNode *next;
    BiLinkNode(int v): val(v), prev(NULL), next(NULL) { }
};

int cap;
int count;
BiLinkNode *head;
BiLinkNode *tail;
map<int, BiLinkNode *> cacheMap;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());

	return 0;
}