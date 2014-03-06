#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> numList;

int getNewEnd(int start, int end)
{
	int i = start + 1;
	while(i < end) {
		if(numList[i] == - numList[start]) {
			return i;
		} else {
			i++;
		}
	}
	return -1;
}

bool proceedList(int start, int end, int *inSum) 
{
	int curr = numList[start];
	if(curr >= 0) {
		return false;
	} else {
		int i = start + 1;
		int currSum = 0;
		while(i < end) {
			int pos = getNewEnd(i, end);
			if(pos == -1) {
				return false;
			}
			int tmp;
			bool result = proceedList(i, pos, &tmp);
			if(!result) {
				return false;
			} else {
				currSum += tmp;
				i = pos + 1;
			}
		}
		if(currSum < -curr) {
			*inSum = -curr;
			return true;
		} else {
			return false;
		}
	}
}


int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string str;
	while(getline(cin, str)) {
		numList.clear();
		stringstream ss(str);
		int val;
		while(ss >> val) {
			numList.push_back(val);
		}
		if(numList.size() == 0) {
			cout << ":-( Try again." << endl;
			continue;
		}
		int sum;
		int pos = getNewEnd(0, numList.size());
		if(pos == -1) {
			cout << ":-( Try again." << endl;
			continue;
		}
		bool result = proceedList(0, pos, &sum);
		if(result) {
			cout << ":-) Matrioshka!" << endl;
		} else {
			cout << ":-( Try again." << endl;
		}
	}
	return 0;
}