#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string tmpStr1;
	while(getline(cin, tmpStr1)) {
		string expr;
		int al[26];//数组初始化！ 
		for(int i = 0; i < 26; i++) {
			al[i] = i + 1;
		}
		int bl[26] = {0};
		bool visited[26] = {false};
		int status = 0;
		string tmpStr;
		for(int i = 0; i < tmpStr1.size(); i++) {
			if(isblank(tmpStr1[i])) {
				continue;
			} else {
				tmpStr += tmpStr1[i];
			}
		}
		for(int i = 0; i < tmpStr.size(); i++) {
			if(status == 0) {
				if(islower(tmpStr[i])) {
					expr += tmpStr[i];
					visited[tmpStr[i] - 'a'] = true;
					if(tmpStr[i + 1] == '+' && tmpStr[i + 2] == '+') {
						bl[tmpStr[i] - 'a']++;
						i += 2;
					} else if(tmpStr[i + 1] == '-' && tmpStr[i + 2] == '-') {
						bl[tmpStr[i] - 'a']--;
						i += 2;
					}
					status = 1;
				} else if(tmpStr[i] == '-' && tmpStr[i + 1] == '-') {
					al[tmpStr[i + 2] - 'a']--;
					expr += tmpStr[i + 2];
					visited[tmpStr[i + 2] - 'a'] = true;
					i += 2;
					status = 1;
				} else if(tmpStr[i] == '+' && tmpStr[i + 1] == '+') {
					al[tmpStr[i + 2] - 'a']++;
					expr += tmpStr[i + 2];
					visited[tmpStr[i + 2] - 'a'] = true;
					i += 2;
					status = 1;
				}
			} else if(status == 1) {
				expr += tmpStr[i];
				status = 0;
			}		
		}
		int result = al[expr[0] - 'a'];
		for(int i = 1; i < expr.size(); i++) {
			char op = expr[i];
			int tmp = al[expr[++i] - 'a'];
			if(op == '+') {
				result += tmp;
			} else {
				result -= tmp;
			}
		}
		
		cout << "Expression: " << tmpStr1 << endl;
		cout << "    value = " << result << endl;
		for(int i = 0; i < 26; i++) {
			al[i] += bl[i];
			if(visited[i]) {
				cout << "    " << static_cast<char>('a' + i) <<	" = " << al[i] << endl;
			}
		}		
	}
	return 0;
}