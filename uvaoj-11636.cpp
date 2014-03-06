#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int num;
	int i = 1;
	cin >> num;
	while(num > 0) {
		
		int count = 0; 
		int val = 1;
		while(val < num) {
			val <<= 1;
			count++;
		}
		
		cout << "Case " << i << ": " << count << endl;
		cin >> num;
		i++;
	}
	
	return 0;
}