#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream inData("test_input.txt");
	cin.rdbuf(inData.rdbuf());
	int count;
	while(true) {
		cin >> count;
		cin.get();
		if(count == 0) {
			break;
		}
		vector<int> disList;
		int minDis = 10000;
		for(int i = 0; i < count; i++) {
			string str;
			getline(cin, str);
			int start = 0;
			int end = 0;
			int status = 0;
			for(int j = 0; j < str.size(); j++) {
				if(status == 0 && str[j] == 'B') {
					status = 1;
					start = j;
				} else if(status == 1 && str[j] == 'X') {
					status = 2;
					end = j;
				}
			}
			if(status == 0) {
				disList.push_back(0);
				minDis = 0;
			} else {
				disList.push_back(end - start);
				if(end - start < minDis) {
					minDis = end - start;
				}
			}	
		}
		int total = 0;
		for(int i = 0; i < disList.size(); i++) {
			total += (disList[i] - minDis);
		}
		cout << total << endl;
	}
	return 0;
}