#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> ptrees;

void getRange(int idx, int &left, int &right)
{
	while(left >= 0 && ptrees[idx][left] == '-') {
		left--;
	}
	left++;
	while(right < ptrees[idx].size() && ptrees[idx][right] == '-') {
		right++;
	}
}

string processTree(int idx, int start, int end)
{
	string resultStr = "(";
	string str = ptrees[idx];
	int left, right;
	for(int i = start; i < end && i < str.size(); i++) {
		if(str[i] == ' ') {
			continue;
		} else {
			resultStr += str[i];
			if(idx + 1 < ptrees.size() && ptrees[idx + 1][i] == '|') {
				left = i;
				right = i;
				getRange(idx + 2, left, right);
				resultStr += processTree(idx + 3, left, right);
			} else {
				resultStr += "()";
			}
		}
	}
	resultStr += ')';
	//cout << resultStr << endl;
	return resultStr;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	while(count--) {
		ptrees.clear();
		string str;
		while(true) {
			getline(cin, str);
			if(str[0] != '#') {
				ptrees.push_back(str);
			} else if(str[0] == '#') {
				break;
			}
		}
		if(ptrees.size() > 0) {
			string buildedStr = processTree(0, 0, ptrees[0].size());
			cout << buildedStr << endl;
		} else {
			cout << "()" << endl;
		}	
	}
	
	return 0;
}