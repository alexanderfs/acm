#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int roundCount = 1;
	while(true) {
		int depth;
		cin >> depth;
		if(depth == 0) {
			break;
		}
		cout << "S-Tree #" << roundCount++ << ":" << endl;
		string tmp;
		vector<int> voList;
		for(int i = 0; i < depth; i++) {
			cin >> tmp;
			voList.push_back(tmp[1] - '0');
		}
		cin >> tmp;
		int count;
		cin >> count;
		string tmp2;
		int offset = (1 << depth) - 1;
		for(int i = 0; i < count; i++) {
			cin >> tmp2;
			int result = 1;
			for(int j = 0; j < depth; j++) {
				int idx = voList[j] - 1;
				int val = tmp2[idx] - '0';	
				if(val == 0) {
					result = result * 2;
				} else {
					result = result * 2 + 1;
				}
			}
			
			cout << tmp[result - offset - 1];
		}
		cout << endl << endl;
	}
	return 0;
}