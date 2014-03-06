#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

vector<string> strList;
vector<int> resultList;
int w, h;

void getCell(string &str, int start, int end, int &x, int &y)
{
	string s1, s2;
	while(start < end) {
		if(isupper(str[start])) {
			s1 += str[start];
		} else {
			s2 += str[start];
		}
		start++;
	}
	y = 0;
	for(int i = 0; i < s1.size(); i++) {
		y = y * 26 + s1[i] - 'A' + 1;
	}
	y--;
	x = 0;
	for(int i = 0; i < s2.size(); i++) {
		x = x * 10 + s2[i] - '0';
	}
	x--;
}

int calcCell(int i, int j)
{
	string tmp = strList[i * w + j];
	int val = 0;
	if(tmp[0] == '=') {
		int pos = 0;
		int pre = 0;
		while(pos < tmp.size()) {
			pos = tmp.find('+', pos + 1);
			if(pos == string::npos) {
				pos = tmp.size();
			}
			int x, y;
			getCell(tmp, pre + 1, pos, x, y);
			val += calcCell(x, y);
			pre = pos;
		}
	} else {
		for(int i = 0; i < tmp.size(); i++) {
			val = val * 10 + tmp[i] - '0';
		}
	}
	resultList[i * w + j] = val;
	return val;
}

void proceedCalc()
{
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			calcCell(i, j);
		}
	}
}

void printResult()
{
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(j < w - 1) {
				cout << resultList[i * w + j] << " ";
			} else {
				cout << resultList[i * w + j];
			}
		}
		cout << endl;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	
	while(count--) {
		cin >> w >> h;
		string tmp;
		for(int i = 0; i < w * h; i++) {
			cin >> tmp;
			strList.push_back(tmp);
		}
		resultList.resize(h * w);
		proceedCalc();
		printResult();
		strList.clear();
		resultList.clear();
	}
	return 0;
}