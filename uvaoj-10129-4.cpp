#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

#define ASIZE 26
#define BSIZE 30
int wordGraph[BSIZE][BSIZE];
int wordVisit[BSIZE];
int wordIn[BSIZE];
int wordOut[BSIZE];

void initGraph() 
{
	memset(wordVisit, 0, sizeof(wordVisit));
	memset(wordIn, 0, sizeof(wordIn));
	memset(wordOut, 0, sizeof(wordOut));
	memset(wordGraph, 0, sizeof(wordGraph));
}

bool checkEuler() 
{
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < ASIZE; i++) {
		if(wordOut[i] == wordIn[i]) {
			a++;
		} else if(wordOut[i] - wordIn[i] == 1) {
			b++;
		} else if(wordOut[i] - wordIn[i] == -1) {
			c++;
		}
	}
	if(a == 26 || (a == 24 && b == 1 && c== 1)) {
		return true;
	} else {
		return false;
	}
}

void dfs(int x)
{
	wordVisit[x] = 2;
	for(int i = 0; i < ASIZE; i++) if(i != x){
		if(wordGraph[x][i] && wordVisit[i] == 1) {
			dfs(i);
		}
	}
	wordVisit[x] = 3;
}

bool checkDfs()
{
	for(int i = 0; i < ASIZE; i++) {
		for(int j = 0; j < ASIZE; j++) {
			if(wordGraph[i][j]) {
				wordVisit[i] = wordVisit[j] = 1;
			}
		}
	}
	
	bool isOk = true;
	int x;
	for(int i = 0; isOk && i < ASIZE; i++) {
		for(int j = 0; isOk && j < ASIZE; j++) {
			if(wordGraph[i][j]) {
				x = i;
				isOk = false;
			}
		}
	}
	
	dfs(x);
	
	for(int i = 0; i < ASIZE; i++) {
		if(wordVisit[i] == 1 || wordVisit[i] == 2) {
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("test_input.txt", "r", stdin);
	
	int count;
	scanf("%d", &count);
	while(count--) {
		int num;
		scanf("%d", &num);
		getchar();
		//cin.get();
		if(num == 1) {
			//cout << "Ordering is possible." << endl;
			printf("Ordering is possible.\n");
			continue;
		}
		initGraph();
		//string tmp;
		char tmp[1010];
		while(num--) {
			//getline(cin, tmp);
			scanf("%s", tmp);
			printf("*****%s\n", tmp);
			//size_t len = tmp.size();
			int len = strlen(tmp);
			
			wordGraph[tmp[0] - 'a'][tmp[len - 1] - 'a'] = 1;
			wordGraph[tmp[len - 1] - 'a'][tmp[0] - 'a'] = 1;
			wordIn[tmp[len - 1] - 'a']++;
			wordOut[tmp[0] - 'a']++;
		}
		bool result1 = checkEuler();
		if(result1) {
			bool result2 = checkDfs();
			if(result2) {
				printf("Ordering is possible.\n");
			} else {
				//cout << "The door cannot be opened." << endl;
				printf("The door cannot be opened.\n");
			}
		} else {
			printf("The door cannot be opened.\n");
		}
	}
}