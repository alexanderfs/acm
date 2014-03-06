#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int mxList[26][2];
int mxNum;

int getEndPos(string str, int start)
{
	int count  = 1;
	int i = start + 1;
	while(i < str.size() && count != 0) {
		if(str[i] == '(') {
			count++;
		} else if(str[i] == ')') {
			count--;
		}
		i++;
	}
	return i;
}

void proceedCal(string str, int start, int end) {
	if(isupper(str[start])) {
		cout << mxList[str[start] - 'A'][0] << ", " << mxList[str[start] - 'A'][1] << endl;
		
	} else {
		int newend = getEndPos(str, start);
		proceedCal(str, start + 1, newend);
		if(isupper(str[newend + 1])) {
			cout << mxList[str[newend + 1] - 'A'][0] << ", " << mxList[str[newend + 1] - 'A'][1] << endl;
		} else {
			int newend2 = getEndPos(str, newend + 1);
			proceedCal(str, newend + 1, newend2);
		}
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	cin >> mxNum;
	char tmp;
	for(int i = 0; i < mxNum; i++) {
		cin >> tmp >> mxList[i][0] >> mxList[i][1];
	}
	cin.get();
	int x = 0;
	int y = 0;
	string strTmp;
	int count = 0;
	while(cin >> strTmp) {
		cout << "::" << count++ << endl;
		if(isupper(strTmp[0])) {
			cout << 0 << endl;
		} else if(strTmp[0] == '('){
			proceedCal(strTmp, 1, strTmp.size() - 1);
		}
	}
	
	return 0;
}