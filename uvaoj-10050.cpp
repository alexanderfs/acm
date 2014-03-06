#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("test_input.txt");
	cin.rdbuf(input.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		int len;
		cin >> len;
		int *dayList = new int[len]();
		int pNum;
		cin >> pNum;
		int *pList = new int[pNum]();
		for(int i = 0; i < pNum; i++) {
			cin >> pList[i];
			int j = 1;
			int h = pList[i] - 1;
			while(h < len) {
				if(h % 7 != 5 && h % 7 != 6) {
					dayList[h] = 1;
				}
				h += pList[i];
			}
		}
		int sum = 0;
		for(int i = 0; i < len; i++) {
			if(dayList[i] == 1) {
				sum++;
			}
		}
		cout << sum << endl;
		delete [] pList;
		delete [] dayList;
	}
	return 0;
}