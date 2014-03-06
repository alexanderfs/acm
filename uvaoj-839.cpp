#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct node {
	int dl;
	int dr;
	int wl;
	int wr;
	struct node *lc;
	struct node *rc;
} NODE;

NODE *buildTree()
{
	int wl, dl, wr, dr;
	cin >> wl >> dl >> wr >> dr;
	NODE *nnode = new NODE;
	if(wl == 0) {
		nnode->lc = buildTree();
	} else {
		nnode->lc = NULL;
	}
	if(wr == 0) {
		nnode->rc = buildTree();
	} else {
		nnode->lc = NULL;
	}
	nnode->wl = wl;
	nnode->wr = wr;
	nnode->dl = dl;
	nnode->dr = dr;
	return nnode;
}

bool result = true;

int judgeBalance(NODE *ptr)
{
	int wl = ptr->wl;
	if(wl == 0) {
		wl = judgeBalance(ptr->lc);	
	}
	int wr = ptr->wr;
	if(wr == 0) {
		wr = judgeBalance(ptr->rc);
	}
	if(wl * ptr->dl != wr * ptr->dr) {
		result = false;
	} else {
		result = true;
	}
	
	return wl + wr;
}

void freeTree(NODE *ptr)
{
	if(ptr->lc != NULL) {
		freeTree(ptr->lc);
	}
	if(ptr->rc != NULL) {
		freeTree(ptr->rc);
	}
	delete ptr;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	while(count--) {
		NODE *root = buildTree();
		judgeBalance(root);
		if(result) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		if(count) {
			cout << endl;
		}
		freeTree(root);
		result = true;
	}	
	return 0;
}