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

struct listnode {
	int val;
	listnode *next;
	listnode(int v): val(v), next(NULL) {}
};

listnode *head = NULL;

listnode *buildprintLL(void) {
	int v;
	scanf("%d", &v);
	if(v == -1) {
		return NULL;
	}
	listnode *p = NULL;
	p = new listnode(v);
	p->next = buildprintLL();
	printf("%d\n", p->val);
	return p;
}

void deleteLL(listnode *p) {
	if(p != NULL) {
		delete(p->next);
		delete p;
	}
}

int main() {
	freopen("test_input.txt", "r", stdin);
	head = buildprintLL();
	deleteLL(head);
	return 0;
}