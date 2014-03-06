#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int inter[201];
int graph[201][201];
int n;
int r;

bool judgeValid()
{
	if(r == 0) {
		return false;
	}
	for(int i = 0; i < n; i++) {
		if(inter[i] % 2 == 1) {
			return false;
		}
	}
	return true;
}

int getStart()
{
	for(int i = 0; i < n; i++) {
		if(inter[i] != 0) {
			return i;
		}
	}
}

void euler(int u)
{
	for(int i = 0; i < n; i++) {
		if(graph[u][i] > 0) {
			graph[u][i]--;
			graph[i][u]--;
			euler(i);
		}
	}
}

bool checkEmpty()
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(graph[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void clearJob()
{
	for(int i = 0; i < n; i++) {
		inter[i] = 0;
		for(int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> n >> r) {
		int a, b;
		for(int i = 0; i < r; i++) {
			cin >> a >> b;
			graph[a][b]++;
			graph[b][a]++;
			inter[a]++;
			inter[b]++;
		}
		bool isValid = judgeValid();
		if(!isValid) {
			cout << "Not Possible" << endl;
		} else {
			int start = getStart();
			euler(start);
			bool result = checkEmpty();
			if(result) {
				cout << "Possible" << endl;
			} else {
				cout << "Not Possible" << endl;
			}
		}
		clearJob();
	}
	return 0;
}