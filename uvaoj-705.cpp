#include <iostream>
#include <fstream>

using namespace std;
int w, h;
char graphslash[76][76];
char graph[152][152];
char visit[152][152];
int maxlen;
int circleCount;
int len;
bool isborder;

int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

void cleanJob()
{
	for(int i = 0; i < h * 2; i++) {
		for(int j = 0; j < w * 2; j++) {
			visit[i][j] = 0;
			graph[i][j] = 0;
		}
	}
	maxlen = 0;
	circleCount = 0;
	len = 0;
	isborder = false;
}

bool judgeBorder(int x, int y)
{
	if(x == 0 || x == 2 * h - 1 || y == 0 || y == 2 * w - 1) {
		return true;
	} else {
		return false;
	}
}

void dfs(int x, int y)
{
	int direction;
	visit[x][y] = 1;
	len++;
	if(judgeBorder(x, y)) {
		isborder = true;
	}
	if(graphslash[x / 2][y / 2] == '/') {
		direction = 1;
	} else {
		direction = 2;
	}
	int nx, ny;
	for(int i = 0; i < 8; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx >= 0 && nx < 2 * h && ny >= 0 && ny < 2 * w) {
			if(i < 4) {
				if(graph[nx][ny] == 0 && visit[nx][ny] == 0) {
					dfs(nx, ny);
				}
			} else if(i >= 4 && i < 6 && direction == 1) {
				if(graph[nx][ny] == 0 && visit[nx][ny] == 0) {
					dfs(nx, ny);
				}
			} else if(i >= 6 && direction == 2){
				if(graph[nx][ny] == 0 && visit[nx][ny] == 0) {
					dfs(nx, ny);
				}
			}
		}	
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count = 1;
	while(cin >> w >> h) {
		if(w == 0 && h == 0) {
			break;
		}
		for(int i = 0; i < h; i++) {
			cin >> graphslash[i];
		}
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(graphslash[i][j] == '/') {
					graph[i * 2][j * 2] = 0;
					graph[i * 2][j * 2 + 1] = 1;
					graph[i * 2 + 1][j * 2] = 1;
					graph[i * 2 + 1][j * 2 + 1] = 0;
				} else if(graphslash[i][j] == '\\') {
					graph[i * 2][j * 2] = 1;
					graph[i * 2][j * 2 + 1] = 0;
					graph[i * 2 + 1][j * 2] = 0;
					graph[i * 2 + 1][j * 2 + 1] = 1;
				}
			}
		}
		for(int i = 0; i < h * 2; i++) {
			for(int j = 0; j < w * 2; j++) {
				if(graph[i][j] == 0 && visit[i][j] == 0) {
					dfs(i, j);
					if(!isborder && len > maxlen) {
						maxlen = len;
					}
					if(!isborder) {
						circleCount++;
					}
					len = 0;
					isborder = false;
				}
			}
		}
		cout << "Maze #" << count++ << ":" << endl;
		if(maxlen != 0) {
			cout << circleCount << " Cycles; the longest has length " << maxlen << "." << endl;
		} else {
			cout << "There are no cycles." << endl;
		}
		cout << endl;
		cleanJob();
	}

	return 0;
}