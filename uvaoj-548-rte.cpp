#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct node {
	int val;
	struct node *lc;
	struct node *rc;
} NODE;

int minVal = 1000000000;
int minLeaf = 100001;
vector<int> inList;
vector<int> postList;

int findPos(int val)
{
	int len = inList.size();
	for(int i = 0; i < len; i++) {
		if(inList[i] == val) {
			return i;
		}
	}
	return -16;//never happen...
}

NODE *buildTree(int start1, int end1, int start2, int end2)
{
	if(end1 == start1) {
		NODE *newNode = new NODE;
		newNode->val = inList[start1];
		newNode->lc = NULL;
		newNode->rc = NULL;
		return newNode;
	} else if(end1 > start1 && start1 >= 0){
		NODE *newNode = new NODE;
		newNode->val = postList[end2];
		int pos = findPos(postList[end2]);
		newNode->lc = buildTree(start1, pos - 1, start2, pos - 1);
		newNode->rc = buildTree(pos + 1, end1, pos, end2 - 1);
		return newNode;
	} else {
		return NULL;
	}
}

void calcMin(NODE *ptr, int currSum)
{
	if(ptr == NULL) {
		return;	
	} else if(ptr->lc == NULL && ptr->rc == NULL) {
		currSum += ptr->val;
		if(currSum < minVal) {
			minVal = currSum;
			minLeaf = ptr->val;
		} else if(currSum == minVal && ptr->val < minLeaf) {
			minLeaf = ptr->val;
		}
	} else {
		calcMin(ptr->lc, currSum + ptr->val);
		calcMin(ptr->rc, currSum + ptr->val);
	}
}

void freeTree(NODE *ptr) 
{
	if(ptr == NULL) {
		return;
	} else {
		freeTree(ptr->lc);
		freeTree(ptr->rc);
		delete ptr;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	string str1;
	string str2;
	while(getline(cin, str1)) {
		getline(cin, str2);
		int tmp;
		stringstream ss(str1);
		while(ss >> tmp) {
			inList.push_back(tmp);
		}
		stringstream ss2(str2);
		while(ss2 >> tmp) {
			postList.push_back(tmp);
		}
		
		NODE *root = buildTree(0, inList.size() - 1, 0, postList.size() - 1);
		calcMin(root, 0);
		cout << minLeaf << endl;
		freeTree(root);
		minVal = 1000000000;
		minLeaf = 1000000;
		inList.clear();
		postList.clear();
	}
	
	return 0;
}