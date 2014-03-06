#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	for(int ii = 1; ii <= count; ii++) {
		string tc;
		getline(cin, tc);
		double p = .0;
		double i = .0;
		double u = .0;
		bool pflag = false;
		bool iflag = false;
		bool uflag = false;
		unsigned int pos = tc.find('=', 0);
		char concept = tc[pos - 1];
		if(concept == 'P') {
			pflag = true;
		} else if(concept == 'U') {
			uflag = true;
		} else if(concept == 'I') {
			iflag = true;
		}
		int i1 = pos + 1;
		string val;
		while(tc[i1] == '.' || isdigit(tc[i1])) {
			val += tc[i1];
			i1++;
		}
		double val1 = atof(val.c_str());
		if(tc[i1] == 'm') {
			val1 = val1 / 1000;
		} else if(tc[i1] == 'k') {
			val1 = val1 * 1000;
		} else if(tc[i1] == 'M') {
			val1 = val1 * 1000000;
		}
		if(pflag) {
			p = val1;
		} else if(uflag) {
			u = val1;
		} else if(iflag) {
			i = val1;
		}
		
		pos = tc.find('=', i1);
		concept = tc[pos - 1];
		int indicator2 = 0;
		if(concept == 'P') {
			indicator2 = 1;
			pflag = true;
		} else if(concept == 'U') {
			indicator2 = 2;
			uflag = true;
		} else if(concept == 'I') {
			indicator2 = 3;
			iflag = true;
		}
		int i2 = pos + 1;
		string val2;
		while(tc[i2] == '.' || isdigit(tc[i2])) {
			val2 += tc[i2];
			i2++;
		}
		double val3 = atof(val2.c_str());
		if(tc[i2] == 'm') {
			val3 = val3 / 1000;
		} else if(tc[i2] == 'k') {
			val3 = val3 * 1000;
		} else if(tc[i2] == 'M') {
			val3 = val3 * 1000000;
		}
		if(indicator2 ==  1) {
			p = val3;
		} else if(indicator2 == 2) {
	 		u = val3;
		} else if(indicator2 == 3) {
			i = val3;
		}
		
		cout << "Problem #" << ii << endl;
		
		if(!pflag) {
			cout << fixed << "P=" << setprecision(2) << u * i << "W" << endl;
		} else if(!uflag) {
			cout.unsetf(ios::scientific);
		 	cout.setf(ios::showpoint);
			cout << fixed<< "U=" << setprecision(2) << p / i << "V" << endl;
		} else if(!iflag) {
			cout.unsetf(ios::scientific); 
		 	cout.setf(ios::showpoint);
			cout << fixed<< "I=" << setprecision(2) << p / u << "A" << endl;
		}
		cout << endl;
	}
	return 0;
}