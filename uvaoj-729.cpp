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
	int n, h;
	char str[17];
	cin >> count;
	while(count--) {
		cin >> n >> h;
		for(int i = 0; i < n - h; i++) {
			str[i] = '0';
		}
		for(int i = n - h; i < n; i++) {
			str[i] = '1';
		}
		str[n] = '\0';
		do {
			cout << str << endl;
		} while(next_permutation(&str[0], &str[n]));
		if(count) {
			cout << endl;
		}
	}
	return 0;
}