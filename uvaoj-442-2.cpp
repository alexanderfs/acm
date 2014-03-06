#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int mxList[26][2];
int mxNum;
typedef struct dimen{
	int x;
	int y;
	int sum;
} DIMEN;

const char *getNewEnd(const char *start)
{
	const char *tmp = start;
	int count = 0;
	if(*tmp == '(') {
		count++;
		tmp++;
	}
	while(count > 0) {
		if(*tmp == '(') {
			count++;
		} else if(*tmp == ')') {
			count--;
			if(!count) {
				break;
			}
		}
		tmp++;
	}
	return tmp;
}

bool proceedMat(const char *start, const char *end, DIMEN *result)
{
	if(isupper(*start)) {
		int idx = *start - 'A';
		result->x = mxList[idx][0];
		result->y = mxList[idx][1];
		result->sum = 0;
		return true;
	} else {
		const char *newEnd1 = getNewEnd(start + 1);
		DIMEN op1;
		bool result1 = proceedMat(start + 1, newEnd1, &op1);
		if(!result1) {
			return false;
		}
		const char *newEnd2 = getNewEnd(newEnd1 + 1);
		DIMEN op2;
		bool result2 = proceedMat(newEnd1 + 1, newEnd2, &op2);
		if(!result2) {
			return false;
		}
		if(op1.y != op2.x) {
			return false;
		} else {
			result->x = op1.x;
			result->y = op2.y;
			result->sum = op1.x * op2.y * op1.y + 
				op1.sum + op2.sum;
			return true;
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
		DIMEN calcSum;
		bool isValid = proceedMat(strTmp.c_str(), strTmp.c_str() + strTmp.size() - 1, &calcSum);
		if(isValid) {
			cout << calcSum.sum << endl;
		} else {
			cout << "error" << endl;
		}
	}
	return 0;
}