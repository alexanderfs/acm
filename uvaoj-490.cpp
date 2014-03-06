#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	vector<string> strList;
	string strTemp;
	int maxLen = 0;
	while(getline(cin, strTemp)) {
		strList.push_back(strTemp);
		
		if(strTemp.size() > maxLen) {
			maxLen = strTemp.size();
		}
	}
	
	for(int i = 0; i < maxLen; i++) {
		for(int j = strList.size() - 1; j >= 0; j--) {
			if(i < strList[j].size()) {
				cout << strList[j][i];
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}
	
	
	return 0;
}