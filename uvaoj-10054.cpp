#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int degree[51];
int graph[51][51];
bool visit[51][51];

bool judgeCircle()
{
	for(int i = 0; i < 51; i++) {
		if(degree[i] % 2 == 1) {
			return false;
		}
	}
	return true;
}

int getStart()
{
	for(int i = 0; i < 51; i++) {
		if(degree[i] != 0) {
			return i;
		}
	}
}

void euler(int u)
{
	for(int i = 0; i < 51; i++) {
		if(graph[u][i] > 0) {
			graph[u][i]--;
			graph[i][u]--;
			euler(i);
			cout << i << " " << u << endl;
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	int baseCount = 1;
	cin >> count;
	int ncount;
	int a, b;
	while(count--) {
		cin >> ncount;
		for(int i = 0; i < ncount; i++) {
			cin >> a >> b;
			graph[a][b]++;
			graph[b][a]++;
			degree[a]++;
			degree[b]++;
		}
		bool isCircle = judgeCircle();
		if(!isCircle) {
			cout << "Case #" << baseCount++ << endl;
			cout << "some beads may be lost" << endl;
			cout << endl;
		} else {
			int start = getStart();
			cout << "Case #" << baseCount++ << endl;
			euler(start);
			if(count != 0) {
				cout << endl;
			}
		}
		memset(degree, 0, sizeof(degree));
		memset(graph, 0, sizeof(graph));
		memset(visit, 0, sizeof(visit));
	}
	
	return 0;
}