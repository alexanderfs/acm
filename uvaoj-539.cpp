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

int graph[25][25];
int visit[25][25];
int n, m;
int maxlen;

void dfs(int start, int count)
{
	for (int i = 0; i < n; i++) {
		if (graph[start][i] && !visit[start][i] && !visit[i][start]) {
			visit[start][i] = visit[i][start] = 1;
			if (count + 1 > maxlen) {
				maxlen = count + 1;
			}
			dfs(i, count + 1);
			visit[start][i] = visit[i][start] = 0;
		}
	}
}

void cleanJob()
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			//visit[i][j] = visit[j][i] = 0;
			graph[i][j] = graph[j][i] = 0;
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while (cin >> n >> m) {
		if (n == 0) {
			break;
		}
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			graph[a][b] = graph[b][a] = 1;
		}
		int result = 0;
		maxlen = 0;
		for (int i = 0; i < n; i++) {
			dfs(i, 0);
			if (result < maxlen) {
				result = maxlen;
			}
			//cleanJob();
		}
		cout << result << endl;
		cleanJob();

	}
	return 0;
}