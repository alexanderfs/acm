#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <iterator>
using namespace std;

typedef struct node {
	int val;
	node *lc;
	node *rc;
} NODE;

NODE *buildTree()
{
	int tmp;
	cin >> tmp;
	if(tmp == -1) {
		return NULL;
	} else {
		NODE *nnode = new NODE;
		nnode->val = tmp;
		nnode->lc = buildTree();
		nnode->rc = buildTree();
		return nnode;
	}
}

map<int, int> leafCount;

void calcSum(NODE *ptr, int idx) 
{
	if(ptr == NULL) {
		return;
	} else {
		leafCount[idx] = leafCount[idx] + ptr->val;
		calcSum(ptr->lc, idx - 1);
		calcSum(ptr->rc, idx + 1);
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
	int count = 1;
	while(true) {
		NODE *root = buildTree();
		if(root == NULL) {
			break;
		}
		cout << "Case " << count++ << ":" << endl;
		calcSum(root, 0);
		map<int, int>::iterator iter = leafCount.begin();
		cout << iter->second;
		iter++;
		for(; iter != leafCount.end(); iter++) {
			cout << " " << iter->second;	
		}
		cout << endl << endl;
		freeTree(root);
		leafCount.clear();
	}
	
	return 0;
}