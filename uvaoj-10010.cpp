#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void lowerStr(string &str)
{
	for(int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

string reverseStr(string str) 
{
	string str1 = str;
	int len = str1.size();
	for(int i = 0; i < len / 2; i++) {
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
	while(count--) {
		int m, n;
		cin >> m >> n;
		cin.get();
		vector<string> dataset;
		string tmp;
		for(int i = 0; i < m; i++) {
			getline(cin, tmp);
			lowerStr(tmp);
			dataset.push_back(tmp);
		}
		int num;
		cin >> num;
		cin.get();
		for(int j = 0; j < num; j++) {
			getline(cin, tmp);
			lowerStr(tmp);
			int x = m + 1;
			int y = n + 1;
			
			//横方向 
			for(int i1 = 0; n >= tmp.size() && i1 < m; i1++) {
				unsigned pos = dataset[i1].find(tmp.c_str(), 0);
				if(pos != string::npos) {
					if(i1 < x || (i1 == x && pos < y)) {
						x = i1;
						y = pos;
					}
				}
				string strr = reverseStr(dataset[i1]);
				pos = strr.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					pos = n - 1 - pos;
					if(i1 < x || (i1 == x && pos < y)) {
						x = i1;
						y = pos;
					}
				}
			}
			//竖方向 
			for(int i2 = 0; m >= tmp.size() && i2 < n; i2++) {
				string str2;
				for(int i3 = 0; i3 < m; i3++) {
					str2 += dataset[i3][i2];
				}
				unsigned pos = str2.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					if(pos < x || (pos == x && i2 < y)) {
						x = pos;
						y = i2;
					}
				}
				
				str2 = reverseStr(str2);
				pos = str2.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					pos = m - 1 - pos;
					if(pos < x || (pos == x && i2 < y)) {
						x = pos;
						y = i2;
					}
				}
			}
			
			//斜1
			for(int i3 = 0; i3 < m; i3++) {
				int i4 = i3;
				int i5 = 0;
				string str3;
				while(i4 < m && i5 < n) {
					str3 += dataset[i4++][i5++];
				}
				if(str3.size() < tmp.size()) {
					continue;
				}
				unsigned pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos && (i3 + pos < x || (i3 + pos == x && pos < y))) {
					x = i3 + pos;
					y = pos;
				}
				str3 = reverseStr(str3);
				pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					pos = str3.size() - 1 - pos;
					if(i3 + pos < x || (i3 + pos == x && pos < y)) {
						x = i3 + pos;
						y = pos;
					}
				}
			}
			
			
			//斜2
			for(int i3 = 1; i3 < n; i3++) {
				int i4 = 0;
				int i5 = i3;
				string str3;
				while(i4 < m && i5 < n) {
					str3 += dataset[i4++][i5++];
				}
				if(str3.size() < tmp.size()) {
					continue;
				}
				unsigned pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos && (pos < x || (pos == x && pos + i3 < y))) {
					y = i3 + pos;
					x = pos;
				}
				str3 = reverseStr(str3);
				pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					pos = str3.size() - 1 - pos;
					if(pos < x || (pos == x && pos + i3 < y)) {
						y = i3 + pos;
						x = pos;
					}
				}
			}
			
			//斜3
			for(int i3 = m - 1; i3 >= 0; i3--) {
				int i4 = i3;
				int i5 = 0;
				string str3;
				while(i4 >= 0 && i5 < n) {
					str3 += dataset[i4--][i5++];
				}
				if(str3.size() < tmp.size()) {
					continue;
				}
				unsigned pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos && (i3 - pos < x || (i3 - pos == x && pos < y))) {
					x = i3 - pos;
					y = pos;
				}
				str3 = reverseStr(str3);
				pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					pos = str3.size() - 1 - pos;
					if(i3 - pos < x || (i3 - pos == x && pos < y)) {
						x = i3 - pos;
						y = pos;
					}
				}
			}
			
			//斜4
			for(int i3 = 1; i3 < n; i3++) {
				int i4 = m - 1;
				int i5 = i3;
				string str3;
				while(i4 >= 0 && i5 < n) {
					str3 += dataset[i4--][i5++];
				}
				if(str3.size() < tmp.size()) {
					continue;
				}
				unsigned pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos && (m - 1 - pos < x || (m - 1 - pos == x && pos + i3 < y))) {
					x = m - 1 - pos;
					y = pos + i3;
				}
				str3 = reverseStr(str3);
				pos = str3.find(tmp.c_str(), 0);
				if(pos != string::npos) {
					pos = str3.size() - 1 - pos;
					if(m - 1 - pos < x || (m - 1 - pos == x && pos + i3 < y)) {
						x = m - 1 - pos;
						y = pos + i3;
					}
				}
			}
			cout << x + 1 << " " << y + 1 << endl;
		}
		if(count != 0) {
			cout << endl;
		}
	}
	return 0;
}