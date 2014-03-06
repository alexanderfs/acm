#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> maze;
int directY[4] = {0, 1, 0, -1};
int directX[4] = {-1, 0, 1, 0};

void findStart(int &x, int &y)
{
	for(int i = 0; i < maze.size(); i++) {
		for(int j = 0; j < maze[i].size(); j++) {
			if(maze[i][j] == '*') {
				x = i;
				y = j;
				return;
			}
		}
	}
	return;
}

void dfs(int x, int y)
{
	maze[x][y] = '*';
	int nx, ny;
	for(int i = 0; i < 4; i++) {
		nx = x + directX[i];
		ny = y + directY[i];
		if(ny < maze[nx].size() && maze[nx][ny] == ' ') {
			dfs(nx, ny);	
		}
	}
	maze[x][y] = '#';
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	while(count--) {
		string tmp;
		while(true) {
			getline(cin, tmp);
			maze.push_back(tmp);
			if(tmp[0] == '_') {
				break;
			}
		}
		int x, y;
		findStart(x, y);
		dfs(x, y);
		for(int i = 0; i < maze.size(); i++) {
			cout << maze[i] << endl;
		}
		maze.clear();
	}
	return 0;
}