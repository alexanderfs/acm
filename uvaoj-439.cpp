#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

int bfs(string &s1, string &s2)
{
	if(s1 == s2) {
		return 0;
	}
	int count = 0;
	queue<string> chessQueue;
	chessQueue.push(s1 + '0');
	while(chessQueue.empty() == false) {
		string top = chessQueue.front();
		if(top[0] == s2[0] && top[1] == s2[1]) {
			return top[2] - '0';
		}
		chessQueue.pop();
		int col;
		int row;
		for(int i = 0; i < 8; i++) {
			col = top[0] + dx[i];
			row = top[1] + dy[i];
			if(col >= 'a' && col <= 'h' && row >= '1' && row <= '8') {
				char ss[4] = {col, row, top[2] + 1, '\0'};
				string newstr(ss);
				chessQueue.push(newstr);
			}
		}
	}	
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string s1, s2;
	while(cin >> s1 >> s2) {
		int count = bfs(s1, s2);
		cout << "To get from " << s1 << " to " << s2 << " takes " << count << " knight moves." << endl;
	}
	return 0;
}