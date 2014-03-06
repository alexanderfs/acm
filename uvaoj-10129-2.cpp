#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define ASIZE 26

int wordGraph[ASIZE][ASIZE];
int wordGraph2[ASIZE][ASIZE];
int inList[ASIZE];
int outList[ASIZE];

void initGraph() 
{
	for(int i = 0; i < ASIZE; i++) {
		for(int j = 0; j < ASIZE; j++) {
			wordGraph[i][j] = 0;
		}
	}
}

void euler(int start)
{
	for(int i = 0; i < ASIZE; i++) {
		if(wordGraph2[start][i] > 0) {
			wordGraph2[start][i]--;
			euler(i);
		}
	}
}

void copyGraph()
{
	for(int i = 0; i < ASIZE; i++) {
		for(int j = 0; j < ASIZE; j++) {
			wordGraph2[i][j] = wordGraph[i][j];
		}
	}
}

bool checkResult()
{
	for(int i = 0; i < ASIZE; i++) {
		for(int j = 0; j < ASIZE; j++) {
			if(wordGraph2[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool getPath()
{
	for(int i = 0; i < ASIZE; i++) {
		for(int j = 0; j < ASIZE; j++) {
			if(wordGraph[i][j]) {
				copyGraph();
				euler(i);
				if(checkResult()) {
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		int num;
		cin >> num;
		cin.get();
		initGraph();
		if(num == 1) {
			cout << "Ordering is possible." << endl;
			continue;
		}
		
		while(num--) {
			string tmp;
			getline(cin, tmp);
			wordGraph[tmp[0] - 'a'][tmp[tmp.size() - 1] - 'a']++;
		}
		
		bool result = getPath();
		if(result) {
			cout << "Ordering is possible." << endl;
		} else {
			cout << "The door cannot be opened." << endl;
		}
	}
	
	return 0;
}