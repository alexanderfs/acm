#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());	
	int count;
	cin >> count;
	while(count--) {
		int am;
		int fq;
		cin >> am >> fq;
		for(int i = 0; i < fq; i++) {
			int j = 1;
			while(j < am) {
				for(int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
				j++;
			}
			while(j > 0) {
				for(int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
				j--;
			}
			if(i < fq - 1) {
				cout << endl;
			}
		}
		if(count != 0) {
			cout << endl;
		}	
	}
	return 0;
}