/*
这样写有两个问题：一个是忽略了首尾相接的情况，另一个是不知道图是不是连通图 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		int count1;
		cin >> count1;
		cin.get();
		vector<int> inList(26, 0);
		vector<int> outList(26, 0);
		string tmp;
		while(count1--) {
			getline(cin, tmp);
			inList[tmp[0] - 'a']++;
			outList[tmp[tmp.size() - 1] - 'a']++;
		}
		int startCount = 0;
		int endCount = 0;
		int middleCount = 0;
		for(int i = 0; i < 26; i++) {
			if(inList[i] - outList[i] == 1) {
				startCount++;
			} else if(outList[i] - inList[i] == 1) {
				endCount++;
			} else if(outList[i] == inList[i]) {
				middleCount++;
			}
		}
		if(startCount == 1 && endCount == 1 && middleCount == 24) {
			cout << "Ordering is possible." << endl;
		} else {
			cout << "The door cannot be opened." << endl;
		}
	}
	return 0;
}