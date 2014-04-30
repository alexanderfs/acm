/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 
 *               
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct listnode {
	listnode *lc;
	listnode *rc;
	int val;
	listnode(int v): val(v), lc(NULL), rc(NULL) {}
};

int preorder[1005];
int inorder[1005];
bool validFlag = true;

listnode *buildBT(int as, int ae, int bs, int be) {
	if(ae - as == 1) {
		if(preorder[as] != inorder[bs]) {
			validFlag = false;
			return NULL;
		}
		listnode *node = new listnode(preorder[as]);
		return node;
	} else if(ae == as) {
		return NULL;
	}
	int i;
	for(i = bs; i < be; i++) if(preorder[as] == inorder[i]) {
		break;
	}
	if(i == be) {
		validFlag = false;
		return NULL;
	}
	int span = i - bs;
	listnode *node = new listnode(preorder[as]);
	node->lc = buildBT(as + 1, as + 1 + span, bs, i);
	if(!validFlag) {
		delete node;
		return NULL;
	}
	node->rc = buildBT(as + 1 + span, ae, i + 1, be);
	if(!validFlag) {
		delete node;
		return NULL;
	}
	return node;
}

void printPostOrder(listnode *root) {
	if(root != NULL) {
		printPostOrder(root->lc);
		printPostOrder(root->rc);
		cout << root->val << " ";
	}
}

void deleteBT(listnode *root) {
	if(root != NULL) {
		deleteBT(root->lc);
		deleteBT(root->rc);
		delete root;
	}
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	
	int len;
	while(cin >> len) {
		for(int i = 0; i < len; i++) {
			cin >> preorder[i];
		}
		for(int i = 0; i < len; i++) {
			cin >> inorder[i];
		}
		listnode *root = buildBT(0, len, 0, len);
		if(!validFlag) {
			cout << "No";
		} else {
			printPostOrder(root);
		}
		cout << endl;
		deleteBT(root);
		validFlag = true;
	}

	return 0;
}