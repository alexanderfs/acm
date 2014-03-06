#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string tmp;
	while(getline(cin, tmp)) {
		string hand;
		string deck;
		stringstream ss(tmp);
		string tmp1;
		
	}
	return 0;
}