#include <iostream>
#include <fstream>

using namespace std;
int p, n;
int clist[100];
char visit[1 << 15];

int getMin(int n)
{
	int val = 0;
	while(n >>= 1) {
		val++;
	}
	return val;
}

int getBitCount(int n)
{
	int count = 0;
	for(int i = 0; i < 17; i++) {
		if(n & (1 << i)) {
			count++;
		}
	}
	return count;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		cin >> p >> n;
		for(int i = 0; i < n; i++) {
			int val = 0;
			int tmp = 0;
			for(int j = 0; j < p; j++) {
				cin >> tmp;
				val = val * 2 + tmp;
			}
			clist[i] = val;
		}
		int min = getMin(n);
		bool isOK = false;
		while(min <= p && !isOK) {
			int max = 1 << p;
			for(int i = 0; i < max && !isOK; i++) {
				if(getBitCount(i) == min) {
					for(int j = 0; j < n; j++) {
						if(visit[clist[j] & i] == 1) {
							isOK = false;
							break;
						} else {
							isOK = true;
							visit[clist[j] & i] = 1;
						}
					}
					for(int j = 0; j < n; j++) {
						visit[clist[j] & i] = 0;
					}
				}
			}
			if(isOK == false) {
				min++;
			}
		}
		cout << min << endl;
	}
	
	return 0;
}