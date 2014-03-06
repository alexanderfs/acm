#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int kn, en;
	int count = 1;
	while(cin >> kn >> en) {
		cin.get();
		vector<string> keyList;
		string strTmp;
		for(int i = 0; i < kn; i++) {
			
			getline(cin, strTmp);
			keyList.push_back(strTmp);
		}
		vector<string> excuseList;
		for(int i = 0; i < en; i++) {
			getline(cin, strTmp);
			excuseList.push_back(strTmp);
		}
		vector<int> wordCount;
		int maxCount = -1;
		for(int i = 0; i < excuseList.size(); i++) {
			string testWord;
			bool isTested = false;
			wordCount.push_back(0);
			for(int j = 0; j < excuseList[i].size(); j++) {
				char tmp = excuseList[i][j];
				if(isalpha(tmp)) {
					isTested = false;
					testWord += tolower(tmp);
				} else if(isTested == false){
					int foundIdx = -1;
					for(int k = 0; k < keyList.size(); k++) {
						if(keyList[k] == testWord) {
							foundIdx = k;
							break;
						}
					}
					if(foundIdx >= 0) {
						wordCount[i]++;	
					}
					testWord = "";
					isTested = true;
				}
			}
			if(!testWord.empty()) {
				int foundIdx = -1;
				for(int k = 0; k < keyList.size(); k++) {
					if(keyList[k] == testWord) {
						foundIdx = k;
						break;
					}
				}
				if(foundIdx >= 0) {
					wordCount[i]++;	
				} 
			}
			if(wordCount[i] > maxCount) {
				maxCount = wordCount[i];
			}
		}
		cout << "Excuse Set #" << count++ << endl;
		for(int i = 0; i < wordCount.size(); i++) {
			if(wordCount[i] == maxCount) {
				cout << excuseList[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}