#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

typedef struct node{
	int val;
	struct node *lchild;
	struct node *rchild;
} NODE;

void freeTree(NODE *ptr)
{
	if(ptr->lchild != NULL) {
		freeTree(ptr->lchild);
	}
	if(ptr->rchild != NULL) {
		freeTree(ptr->rchild);
	}
	delete ptr;
}

int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
	int count;
	cin >> count;
	cin.get();
	string str;
	stack<NODE *> ptrStack;
	while(count--) {
		getline(cin, str);
		int len = str.size();
		for(int i = 0; i < len; i++) {
			if(isupper(str[i])) {
				NODE *rp = ptrStack.top();
				ptrStack.pop();
				NODE *lp = ptrStack.top();
				ptrStack.pop();
				NODE *newPtr = new NODE;
				newPtr->val = str[i];
				newPtr->lchild = lp;
				newPtr->rchild = rp;
				ptrStack.push(newPtr);
				
			} else if(islower(str[i])) {
				NODE *newPtr = new NODE;
				newPtr->val = str[i];
				newPtr->lchild = NULL;
				newPtr->rchild = NULL;
				ptrStack.push(newPtr);
			}
		}
		
		stack<char> charStack;
		queue<NODE *> nodeQueue;
		NODE *root = ptrStack.top();
		nodeQueue.push(ptrStack.top());
		ptrStack.pop();
		NODE *curr = NULL;
		while(!nodeQueue.empty()) {
			curr = nodeQueue.front();
			nodeQueue.pop();
			if(curr->lchild == NULL) {
				charStack.push(curr->val);
				continue;
			}
			nodeQueue.push(curr->lchild);
			nodeQueue.push(curr->rchild);
			charStack.push(curr->val);
		}
		while(!charStack.empty()) {
			cout << charStack.top();
			charStack.pop();
		}
		cout << endl;
		
		freeTree(root);
		
	}
	
	
	return 0;
}