#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
typedef struct node {
	int x, y;
	int cc;
	int cd;
	int ct;
} NODE;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
char graph[27][27];
char visit[27][27];
int mint;

void cleanJob()
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			visit[i][j] = 0;	
		}
	}
}

void getStart(int &sx, int &sy)
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(graph[i][j] == 'S') {
				sx = i;
				sy = j;
				return;
			}
		}
	}
}

int bfs(int sx, int sy)
{
	visit[sx][sy] = 1;
	NODE n1;
	n1.x = sx;
	n1.y = sy;
	n1.cc = 0;
	n1.cd = 0;
	n1.ct = 0;
	queue<NODE> nq;
	nq.push(n1);
	mint = 1 << 30;
	
	while(nq.empty() == false) {
		n1 = nq.front();
		nq.pop();
		int nx, ny;
		for(int i = 0; i < 4; i++) {
			nx = n1.x + dx[i];
			ny = n1.y + dy[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && 
				graph[nx][ny] == '.' && visit[nx][ny] == 0) {
				NODE n2;
				n2.x = nx;
				n2.y = ny;
				n2.cc = (n1.cc + 1) % 5;
				int angle = n1.cd - i;
				if(angle < 0) {
					angle  = -angle;
				}
				if(angle == 3) {
					angle = 1;
				}
				n2.cd = i;
				n2.ct = n1.ct + angle + 1;
				nq.push(n2);
				visit[nx][ny] = 1;
			} else if(nx >= 0 && nx < m && ny >= 0 && ny < n && 
				graph[nx][ny] == 'T') {
					int cc = (n1.cc + 1) % 5;
					int cd = i;
					int angle = n1.cd - i;
					if(angle < 0) {
						angle = -angle;
					}
					if(angle == 3) {
						angle = 1;
					}
					int ct = n1.ct + angle + 1;
					if(cc == 1) {
						ct += 12;
					} else if(cc == 2) {
						ct += 24;
					} else if(cc == 3) {
						ct += 6;
					}
					if(ct < mint) {
						mint = ct;
					}
				}
		}
	}
	
	if(mint == 1 << 30) {
		return -1;
	} else {
		return mint;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 1;
	while(cin >> m >> n) {
		if(m == 0) {
			break;
		}
		for(int i = 0; i < m; i++) {
			cin >> graph[i];
		}
		int sx, sy;
		getStart(sx, sy);
		mint = bfs(sx, sy);
		if(mint < 0) {
			cout << "Case #" << count++ << endl;
			cout << "destination not reachable" << endl;
		} else {
			cout << "Case #" << count++ << endl;
			cout << "minimum time = " << mint << " sec" << endl;
		}
		cleanJob();
	}
	return 0;
}