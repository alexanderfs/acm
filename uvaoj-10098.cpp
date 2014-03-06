#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	string s1;
	cin >> count;
	while(count--) {
		cin >> s1;
		sort(s1.begin(), s1.end());
		do {
			cout << s1 << endl;
		} while(next_permutation(s1.begin(), s1.end()));
		cout << endl;
	}
	return 0;
}