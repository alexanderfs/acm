#include <iostream>
#include <fstream>

using namespace std;
int cherry[50][2];
int n;
int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	while(cin >> n) {
		if(n == 0) {
			break;
		}
		for(int i = 0; i < 2 * n; i++) {
			cin >> cherry[i][0] >> cherry[i][1];
		}
		int c1 = 0, c2 = 0;
		bool isFound = false;
		for(int i = -500; i <= 500 && !isFound; i++) {
			for(int j = -500; j <= 500 && !isFound; j++) {
				c1 = 0;
				c2 = 0;
				for(int k = 0; k < n * 2; k++) {
					if(i * cherry[k][0]+ j * cherry[k][1] > 0) {
						c1++;
					} else if(i * cherry[k][0]+ j * cherry[k][1] < 0) {
						c2++;
					}
				}
				if(c1 == c2 && c1 == n) {
					cout << i << " " << j << endl;
					isFound = true;
				}
			}
		}
	}

	return 0;
}