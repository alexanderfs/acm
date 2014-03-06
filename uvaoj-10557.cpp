#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
typedef struct node {
	int n;
	int cb;
} NODE;

int n;
int energy[105];
char graph[105][105];

void cleanJob()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
		energy[i] = 0;
	}
}

void bfs()
{
	NODE n1;
	n1.n = 0;
	n1.cb = energy[0] + 100;
	queue<NODE> nq;
	nq.push(n1);
	bool isFound = false;
	while (nq.empty() == false && !isFound) {
		NODE n2 = nq.front();
		nq.pop();
		for (int i = 0; i < n; i++) {
			if (graph[n2.n][i] == 1 && n2.cb + energy[i] > 0) {
				NODE n3;
				n3.n = i;
				n3.cb = n2.cb + energy[i];
				nq.push(n3);
				if (i == n - 1) {
					isFound = true;
				}
			}
		}
	}

	if (isFound == true) {
		cout << "winnable" << endl;
	}
	else {
		cout << "hopeless" << endl;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while (cin >> n) {
		if (n == -1) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> energy[i];
			int dc;
			cin >> dc;
			int k;
			for (int j = 0; j < dc; j++) {
				cin >> k;
				graph[i][k - 1] = 1;
			}
		}
		bfs();
		cleanJob();
	}
	return 0;
}