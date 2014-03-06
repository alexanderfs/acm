#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int numIdx[1000000];
vector< queue<int> > queueList(1000);
int main()
{
	ifstream testIn("test_input.txt");
	cin.rdbuf(testIn.rdbuf());
	int count = 0;
	while (true) {
		int qCount = 0;
		cin >> qCount;
		if (qCount == 0) {
			break;
		}
		vector<int> qFlag(qCount, 10000);
		cout << "Scenario #" << ++count << endl;;
		for (int i = 0; i < qCount; i++) {
			while (!queueList[i].empty()) {
				queueList[i].pop();
			}
			int qvCount;
			cin >> qvCount;
			int tmp;
			for (int j = 0; j < qvCount; j++) {
				cin >> tmp;
				numIdx[tmp] = i;
			}
		}
		cin.get();
		int seq = 0;
		int currSeq = -1;
		while (true) {
			string cmd;
			cin >> cmd;
			if (cmd == "ENQUEUE") {
				int tmp;
				cin >> tmp;
				int idx = numIdx[tmp];
				queueList[idx].push(tmp);
				if (qFlag[idx] == 10000) {
					qFlag[idx] = seq++;
				}
			}
			else if (cmd == "DEQUEUE"){
				if (currSeq == -1) {
					int first = 10000;
					int firstIdx = 0;
					for (int i = 0; i < qCount; i++) {
						if (qFlag[i] < first) {
							first = qFlag[i];
							firstIdx = i;
						}
					}
					currSeq = firstIdx;
				}
				cout << queueList[currSeq].front() << endl;;
				queueList[currSeq].pop();
				if (queueList[currSeq].empty()) {
					qFlag[currSeq] = 10000;
					currSeq = -1;
				}

			}
			else if (cmd == "STOP") {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}