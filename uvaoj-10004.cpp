#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char graph[200][200];
int node[200];
int n, l;

bool dfs(int u)
{
	
	for(int i = 0; i < n; i++) {
		if(graph[u][i] == 1 && node[i] == 0) {
			 node[i] = -node[u];
			 if(!dfs(i)) {
			 	return false;
			 }
		} else if(graph[u][i] == 1 && node[u] == node[i]) {
			return false;
		}
	}
	return true;
	
}

void cleanJob()
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
		node[i] = 0;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(true) {
		cin >> n;
		if(n == 0) {
			break;
		}
		cin >> l;
		int a, b;
		for(int i = 0; i < l; i++) {
			cin >> a >> b;
			graph[a][b] = graph[b][a] = 1;
		}
		node[0] = 1;
		if(dfs(0)) {
			cout << "BICOLORABLE." << endl;
		} else {
			cout << "NOT BICOLORABLE." << endl;
		}
		cleanJob();
	}
	
	return 0;
}