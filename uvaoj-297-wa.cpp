#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

int flag = 0;
bitset<1024> image1;
bitset<1024> image2;

void fillPix(int start, int len)
{
	for(int i = 0; i < len; i++) {
		if(flag == 0) {
			image1[start + i] = 1;
		} else {
			image2[start + i] = 1;
		}
	}
}

int proceedTree(string &str, int idx, int depth, int start)
{
	for(int i = 0; i < 4 && idx < 1024; i++) {
		if(str[idx] == 'p') {
			idx = proceedTree(str, idx + 1, depth + 1, start + i * (1 << (10 - 2 * depth)));
		} else if(str[idx] == 'f') {
			int len = (1 << (10 - 2 * depth));
			fillPix(start + i * len, len);
			idx++;
		} else {
			idx++;
		}
	}
	return idx;	
}


int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	string str;
	while(count--) {
		flag = 0;
		image1.reset();
		getline(cin, str);
		proceedTree(str, 0, 0, 0);
		getline(cin, str);
		proceedTree(str, 0, 0, 0);
		cout << "There are " << image1.count() << " black pixels." << endl;
	}
	
	return 0;
}