#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
typedef struct node {
	int x, y, z;
	int t;
} NODE;
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 1, 0, -1, 0, 0};
char dungeon[31][31][31];
char visit[31][31][31];
int l, h, w;

void cleanJob()
{
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < h; j++) {
			for(int k = 0; k < w; k++) {
				visit[i][j][k] = 0;
			}
		}
	}
}

void findStart(int &x, int &y, int &z)
{
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < h; j++) {
			for(int k = 0; k < w; k++) {
				if(dungeon[i][j][k] == 'S') {
					x = i;
					y = j;
					z = k;
					return;
				}
			}
		}
	}
}

void bfs(int sx, int sy, int sz)
{
	visit[sx][sy][sz] = 1;
	NODE n;
	n.x = sx;
	n.y = sy;
	n.z = sz;
	n.t = 0;
	queue<NODE> nq;
	nq.push(n);
	int et = -1;
	bool isFound = false;
	while(nq.empty() == false && !isFound) {
		NODE n1 = nq.front();
		nq.pop();
		int nx, ny, nz;
		for(int i = 0; i < 6; i++) {
			nx = n1.x + dx[i];
			ny = n1.y + dy[i];
			nz = n1.z + dz[i];
			if(nx >= 0 && nx < l &&
				ny >= 0 && ny < h &&
				nz >= 0 && nz < w && dungeon[nx][ny][nz] == '.' &&
				visit[nx][ny][nz] == 0) {
				NODE n2;
				n2.x = nx;
				n2.y = ny;
				n2.z = nz;
				n2.t = n1.t + 1;
				nq.push(n2);
				visit[nx][ny][nz] = 1;	
			} else if(nx >= 0 && nx < l &&
				ny >= 0 && ny < h &&
				nz >= 0 && nz < w && dungeon[nx][ny][nz] == 'E') {
				et = n1.t + 1;
				isFound = true;
				break;	
			}
		}
		
	}
	if(isFound) {
		cout << "Escaped in " << et << " minute(s)." << endl;
	} else {
		cout << "Trapped!" << endl;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	while(cin >> l >> h >> w) {
		if(l == 0) {
			break;
		}
		for(int i = 0; i < l; i++) {
			for(int j = 0; j < h; j++) {
				cin >> dungeon[i][j];
			}
		}
		int sx, sy, sz;
		findStart(sx, sy, sz);
		bfs(sx, sy, sz);
		cleanJob();
	}
	return 0;
}