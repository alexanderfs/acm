#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());

	int count;
	cin >> count;
	cin.get();
	while(count--) {
		string str;
		char strstack[130] = {0};
		int top = 0;
		bool isValid = true;
		getline(cin, str);
		
		for(int i = 0; isValid && i < str.size(); i++) {
			if(str[i] == '(' || str[i] == '[') {
				strstack[top++] = str[i];
			} else if(str[i] == ')') {
				if(top > 0 && strstack[top - 1] == '(') {
					top--;
				} else {
					isValid = false;
				}
			} else if(str[i] == ']') {
				if(top > 0 && strstack[top - 1] == '[') {
					top--;
				} else {
					isValid = false;
				}
			}
		}
		if(top == 0 && isValid) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}