#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void lowerStr(string &str)
{
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

string reverseStr(string str)
{
	string str1 = str;
	int len = str1.size();
	for (int i = 0; i < len / 2; i++) {
		char tmp = str1[i];
		str1[i] = str1[len - 1 - i];
		str1[len - 1 - i] = tmp;
	}
	return str1;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while (count--) {
		int m, n;
		cin >> m >> n;
		cin.get();
		vector<string> dataset;
		string tmp;
		for (int i = 0; i < m; i++) {
			getline(cin, tmp);
			lowerStr(tmp);
			dataset.push_back(tmp);
		}
		int num;
		cin >> num;
		cin.get();
		for (int j = 0; j < num; j++) {
			getline(cin, tmp);
			lowerStr(tmp);
			int x = m + 1;
			int y = n + 1;
			bool isFound = false;
			for (int i1 = 0; !isFound && i1 < m; i1++) {
				for (int i2 = 0; !isFound && i2 < n; i2++) {
					if (tmp[0] != dataset[i1][i2]) {
						continue;
					}
					string str1;
					int i3 = i1;
					int i4 = i2;
					//left
					while (i4 >= 0) {
						str1 += dataset[i3][i4--];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
					//right
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i4 < n) {
						str1 += dataset[i3][i4++];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
					//up
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i3 >= 0) {
						str1 += dataset[i3--][i4];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
					//down
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i3 < m) {
						str1 += dataset[i3++][i4];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
					//NW
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i3 >= 0 && i4 >= 0) {
						str1 += dataset[i3--][i4--];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
					//NE
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i3 >= 0 && i4 < n) {
						str1 += dataset[i3--][i4++];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
					//SW
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i3 < m && i4 >= 0) {
						str1 += dataset[i3++][i4--];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}

					//SE
					str1 = "";
					i3 = i1;
					i4 = i2;
					while (i3 < m && i4 < n) {
						str1 += dataset[i3++][i4++];
					}
					if ((str1.size() >= tmp.size()) &&
						0 == str1.find(tmp.c_str(), 0)) {
						x = i1;
						y = i2;
						isFound = true;
						continue;
					}
				}
			}
			cout << x + 1 << " " << y + 1 << endl;
		}
		if (count != 0) {
			cout << endl;
		}
	}
	return 0;
}