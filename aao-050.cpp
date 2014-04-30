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

#include <cstdio>
#include <cstdlib>

using namespace std;

struct mynode {
	int val;
	mynode *lc;
	mynode *rc;
};

mynode *nodestack1[10005];
int ns1top = 0;
mynode *nodestack2[10005];
int ns2top = 0;

mynode *buildtree() {
	int v;
	scanf("%d", &v);
	if(v == 0) {
		return NULL;
	}
	mynode *curr = new mynode();
	curr->val = v;
	curr->lc = buildtree();
	curr->rc = buildtree();
	return curr;
}

bool getnodepath(mynode *ptr, int m) {
	if(ptr == NULL) {
		return false;
	}
	if(ptr->val == m) {
		return true;
	}
	nodestack1[ns1top++] = ptr;
	bool re = getnodepath(ptr->lc, m);
	if(re == false) {
		re = getnodepath(ptr->rc, m);
		if(re == false) {
			ns1top--;
			return false;
		} else {
			return true;
		}
	} else {
		return true;
	}
}

void cpystack() {
	ns2top = ns1top;
	for(int i = 0; i < ns1top; i++) {
		nodestack2[i] = nodestack1[i];
	}
}

mynode *getcommonancestor() {
	int i = 0;
	while(i < ns1top && i < ns2top && nodestack1[i] == nodestack2[i]) {
		i++;
	}
	if(i == 0) {
		return NULL;
	} else {
		return nodestack1[i - 1];
	}
}

void freetree(mynode *root) {
	if(root == NULL) {
		return;
	}
	freetree(root->lc);
	freetree(root->rc);
	delete root;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	int tcn = 0;
	scanf("%d", &tcn);
	while(tcn--) {
		mynode *root = buildtree();
		int m1, m2;
		scanf("%d %d", &m1, &m2);
		ns1top = ns2top = 0;
		getnodepath(root, m1);
		cpystack();
		ns1top = 0;
		getnodepath(root, m2);
		mynode *ca = getcommonancestor();
		if(ca == NULL) {
			printf("My God\n");
		} else {
			printf("%d\n", ca->val);
		}
		freetree(root);
	}

	return 0;
}