/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : ��һ���ύTLE�������˶��ڱߵķ������飬����˵�㲻���ظ������Ǿ�Ӧ��ֱ���õ�
 ���ظ�������������ˣ�û��Ҫ�������á����԰ѵ���ñߵ��滻��Ч���� 
 ��֦�ķ�ʽ���Ǵ�Ŀ������DFS������Է��ʵ��Ľڵ�ɸѡ�������������޳�һ���ָ����޷�����Ŀ��ڵ�
 �Ľڵ㡣
 ��������ʹ�õ�������DFS�ķ�ʽ��һ���Ǵ��������±���һ���Ǵ���Ԫ��ֵ���ڵڶ��ֵ��У�������Ҫ�ֶ�
 ����ÿ���ݹ�״̬�������±�ֵ�����ַ������Ƚϡ� 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int graph[22][22];
int visitn[22];
int rlist[22];
int target;
int acount;
int rcount;
int possible[22];
int pcount;

void pdfs(int curr)
{
	possible[pcount++] = curr;
	for(int i = 0; i < 22; i++) {
		if(graph[curr][i] && !visitn[i]) {
			visitn[i] = 1;
			pdfs(i);
		}
	}
}

void dfs(int curr)
{
	rlist[acount++] = curr;
	if(curr == target) {
		rcount++;
		for(int i = 0; i < acount; i++) {
			cout << rlist[i];
			if(i < acount - 1) {
				cout << " ";
			}
		}
		cout << endl;
		return;
	}
	
	for(int i = 0; i < pcount; i++) {
		int b = possible[i];
		if(graph[curr][b] && !visitn[b]) {
			visitn[b] = 1;
			dfs(b);
			visitn[b] = 0;
			acount--;
		}
	}
}

/*void dfs(int curr)
{
	if(rlist[curr - 1] == target) {
		rcount++;
		for(int i = 0; i < curr; i++) {
			cout << rlist[i];
			if(i < curr - 1) {
				cout << " ";
			}
		}
		cout << endl;
		return;
	}
	for(int i = 0; i < pcount; i++) {
		int j = possible[i];
		if(graph[rlist[curr - 1]][j] && !visitn[j] ) {
			rlist[curr] = j;
			visitn[j] = 1;
			dfs(curr + 1);
			visitn[j] = 0;
		}
	}
}*/

void cleanJob()
{
	memset(graph, 0, sizeof(graph));
	memset(visitn, 0, sizeof(visitn));
	acount = 0;
	rcount = 0;
	pcount = 0;
	memset(possible, 0, sizeof(possible));
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 1;
	int a, b;
	while(cin >> target) {
		while(true) {
			cin >> a >> b;
			if(a == 0) {
				break;
			}
			graph[a][b] = graph[b][a] = 1;
		}
		visitn[target] = 1;
		pdfs(target);
		sort(possible, possible + pcount);
		memset(visitn, 0, sizeof(visitn));
		cout << "CASE " << count++ << ":" << endl;
		visitn[1] = 1;
		dfs(1);
		cout << "There are " << rcount << " routes from the firestation to streetcorner " << target << "." << endl;
		cleanJob();
	}

	return 0;
}