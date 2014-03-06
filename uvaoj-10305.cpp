#include <iostream>
#include <fstream>
using namespace std;

int graph[101][101];
int n, m;
int visited[101];
int topo[101];
int t;

void dfs(int u)
{
	if(visited[u] == 1) {
		return;
	}
	visited[u] = -1;
	for(int i = 1; i <= n; i++) {
		if(graph[u][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
	visited[u] = 1;
	topo[--t] = u;
}

void clearJob()
{
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			graph[i][j] = 0;
		}
	}
	for(int i = 0; i <= n; i++) {
		visited[i] = 0;
	}
	for(int i = 0; i <= n; i++) {
		topo[i] = 0;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	while(true) {
		cin >> n >> m;
		if(n == 0 && m == 0) {
			break;
		}
		t = n;
		int a, b;
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			graph[a][b] = 1;
		}
		for(int i = 1; i <= n; i++) {
			dfs(i);
		}
		cout << topo[0];
		for(int i = 1; i < n; i++) {
			cout << " " << topo[i];
		}
		cout << endl;
		clearJob();
	}
	return 0;
}