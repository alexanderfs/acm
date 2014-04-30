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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int first[2005];
int u[20000];
int v[20000];
int nexte[20000];
int visit[2005];
int pcount[2005];
int pathdetail[10000];
int pathtotal;
int ncount;
int ecount;

bool dfs(int curr)
{
	if (pathdetail[curr - 1] == ncount) {
		for (int i = 0; i < curr; i++) {
			pcount[pathdetail[i]]++;
		}
		pathtotal++;
		return true;
	}
	int unode = pathdetail[curr - 1];
	for (int e = first[unode]; e != -1; e = nexte[e]) {
		int vnode = v[e];
		if (visit[vnode] == 0) {
			pathdetail[curr] = vnode;
			visit[vnode] = 1;
			dfs(curr + 1);
			visit[vnode] = 0;
		}
	}

}


int main()
{
	//ifstream in("test_input.txt");
	//cin.rdbuf(in.rdbuf());
	freopen("test_input.txt", "r", stdin);
	int tcn;
	//cin >> tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		//cin >> ncount >> ecount;
		scanf("%d %d", &ncount, &ecount);
		pathtotal = 0;
		for (int i = 1; i <= ncount; i++) {
			visit[i] = 0;
			first[i] = -1;
			pcount[i] = 0;
		}
		int a, b;
		for (int i = 0, j = 0; i < ecount; i++) {
			//cin >> u >> v;
			scanf("%d %d", &a, &b);
			u[j] = a;
			v[j] = b;
			nexte[j] = first[a];
			first[a] = j;
			j++;
			u[j] = b;
			v[j] = a;
			nexte[j] = first[b];
			first[b] = j;
			j++;
		}
		pathdetail[0] = 1;
		dfs(1);
		vector<int> nodeList;
		for (int i = 2; i < ncount; i++) if (pcount[i] == pathtotal){
			nodeList.push_back(i);
		}
		//cout << nodeList.size() << endl;
		int len = nodeList.size();
		printf("%d\n%d", len, nodeList[0]);
		//cout << nodeList[0];
		for (int i = 1; i < nodeList.size(); i++) {
			//cout << " " << nodeList[i];
			printf(" %d", nodeList[i]);
		}
		printf("\n");
	}

	return 0;
}