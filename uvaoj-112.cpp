#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

typedef struct node {
	int val;
	struct node *lc;
	struct node *rc; 
} NODE;

void freeTree(NODE *ptr)
{
	if(ptr == NULL) {
		return;
	}
	freeTree(ptr->lc);
	freeTree(ptr->rc);
	free(ptr);

}

bool isSumExist(const NODE *ptr, int sum, int currSum)
{
	int tmp = ptr->val + currSum;
	if(tmp == sum && ptr->lc == NULL && ptr->rc == NULL) {
		return true;	
	}
	if(tmp != sum && ptr->lc == NULL && ptr->rc == NULL) {
		return false;
	}
	bool result;
	if(ptr->lc != NULL) {
		result = isSumExist(ptr->lc, sum, tmp);
	}
	if(result == false && ptr->rc != NULL) {
		result = isSumExist(ptr->rc, sum, tmp);
	}
	
	return result;
}

NODE * buildBTree(const string &str, int start, int end)
{
	if(end - start == 1) {
		return NULL;
	}
	NODE *newNode = new NODE;
	int val = 0;
	int idx = start + 1;
	bool nflag = false;
	if(str[idx] == '-') {
		nflag = true;
		idx++;
	}
	while(idx < end && isdigit(str[idx])) {
		val = val * 10 + str[idx] - '0';
		idx++;
	}
	int idx2 = idx;
	if(nflag) {
		newNode->val = -val;
	} else {
		newNode->val= val;
	}
	int bCount = 0;
	if(str[idx] == '(') {
		bCount++;
		idx++;
	}
	while(bCount != 0) {
		if(str[idx] == '(') {
			bCount++;
		} else if(str[idx] == ')') {
			bCount--;
		}
		idx++;
	}
	
	newNode->lc= buildBTree(str, idx2, idx - 1);
	newNode->rc= buildBTree(str, idx, end - 1);
	
	return newNode;
}

int main()
{
	ifstream inFile("test_input.txt");
	cin.rdbuf(inFile.rdbuf());
	while(true) {
		int sum;
		cin >> sum;
		
		char tmp;
		cin >> tmp;
		while(isblank(tmp)) {
			cin >> tmp;
			if(cin.eof()) {
				break;
			}
		}
		if(cin.eof()) {
			break;
		}
		string treeStr;
		int bCount = 0;
		if(tmp == '(') {
			bCount++;
			treeStr += tmp;
		}
		while(bCount != 0) {
			cin >> tmp;
			if(isblank(tmp)) {
				continue;
			} else {
				treeStr += tmp;
				if(tmp == '(') {
					bCount++;
				} else if(tmp == ')') {
					bCount--;
				}
			}
		}
		if(treeStr == "()") {
			cout << "no" << endl;
			//continue;
		} else {
			NODE *root = buildBTree(treeStr, 0, treeStr.size() - 1);
			bool result = isSumExist(root, sum, 0);
			if(result) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
			freeTree(root);
		}
		//cout << sum << endl;
		//cout << treeStr << endl;
		
	}
	return 0;
}