/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 第一遍提交TLE，还用了对于边的访问数组，这里说点不能重复访问那就应该直接用点
 的重复访问数组就行了，没必要两个都用。可以把点的用边的替换看效果。 
 剪枝的方式就是从目标逆向DFS将其可以访问到的节点筛选出来。这样会剔除一部分根本无法到达目标节点
 的节点。
 另外这里使用到了两种DFS的方式，一种是传递数组下标另一种是传递元素值，在第二种当中，我们需要手动
 保存每个递归状态的数组下标值。两种方法供比较。 
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