#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string str1;
	while(cin >> str1) {
		if(str1[0] == '#') {
			break;
		}
		if(next_permutation(str1.begin(), str1.end())) {
			cout << str1 << endl;
		} else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}