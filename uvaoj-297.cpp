#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

bitset<1024> image1;
int idx;
string istr;

void fillPix(int start, int len)
{
	for(int i = 0; i < len; i++) {
		image1[start + i] = 1;
	}
}

void proceedTree(int depth, int start)
{
	for(int i = 0; i < 4 && idx < 1024; i++) {
		int c = istr[idx++];
		switch(c) {
			case 'p':
				proceedTree(depth + 1, start + i * (1 << (10 - 2 * depth)));
				break;
			case 'f':
				int len = (1 << (10 - 2 * depth));
				fillPix(start + i * len, len);
				break;
			default:
				break;
		}
	}
}


int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	while(count--) {
		image1.reset();
		idx = 0;
		getline(cin, istr);
		proceedTree(0, 0);
		idx = 0;
		getline(cin, istr);
		proceedTree(0, 0);
		cout << "There are " << image1.count() << " black pixels." << endl;
	}
	
	return 0;
}