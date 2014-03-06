#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string exp;
	while(getline(cin, exp)) {
		int num1 = 0;
		int num2 = 0;
		int status = 0;
		int opt = 0;
		
		int count1 = 0;
		int count2 = 0;
		for(int i = 0; i < exp.size(); i++) {
			char c = exp[i];
			if(isdigit(c) && status == 0) {
				num1 = num1 * 10 + (c - '0');
				count1++;
			} else if(c == ' ' && status == 0) {
				status = 1;
			} else if(c == '+' && (status == 1 || status == 0)) {
				opt = 1;
				status = 2;
			} else if(c == '*' && (status == 1 || status == 0)) {
				opt = 2;
				status = 2;
			} else if(isdigit(c) && status == 2) {
				num2 = c - '0';
				status = 3;
			} else if(isdigit(c) && status == 3) {
				num2 = num2 * 10 + (c - '0');
				count2++;
			}
		}
		cout << exp << endl;
		bool isResultOF = false;
		bool isnum1of = false;
		bool isnum2of = false;
		if(count1 > 10 || num1 < 0) {
			isnum1of = true;
			cout << "first number too big" << endl;
		}
		if(count2 > 10 || num2 < 0) {
			isnum2of = true;
			cout << "second number too big" << endl;
		}
		if(opt == 2 && (num1 == 0 || num2 == 0)) {
			continue;
		} else if(opt == 1){
			if(isnum1of || isnum2of) {
				cout << "result too big" << endl;
			} else if(2147483647 - num1 < num2) {
				cout << "result too big" << endl;
			}
		} else if(opt == 2) {
			if(isnum1of || isnum2of) {
				cout << "result too big" << endl;
			} else if(2147483647 / num1 < num2) {
				cout << "result too big" << endl;
			}
		}
		
		
		
	/*	if(count1 > 10 && num1 < 0) {
			cout << "first number too big" << endl;
			isResultOF = true;
		}
		if(count2 > 10 && num2 < 0) {
			cout << "second number too big" << endl;
			isResultOF = true;
		}
		if((num1 == 0 || num2 == 0) && opt == 2) {
			isResultOF = false;
		}
		if(isResultOF == false) {
			int result;
			if(opt == 1) {
				result = num1 + num2;
				
				if(result < num1 || result < num2) {
					isResultOF = true;
				}
			} else if(opt == 2) {
				result = num1 * num2;
				if((num1 > 0 && num2 > 0) && result / num1 != num2) {
					isResultOF = true;
				}
			}
			//cout << result << endl;
		}
		if(isResultOF) {
			cout << "result too big" << endl;
		}*/
		
		
	}
	
	return 0;
}