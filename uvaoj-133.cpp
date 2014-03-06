#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	bool isValid;
} NODE;

NODE nodeList[20];

void initList(int n)
{
	for(int i = 0; i < n; i++)	{
		nodeList[i].num = i + 1;
		nodeList[i].isValid = true;
	}
}

int findnext(int curr, int n)
{
	while(nodeList[++curr % n].isValid == false) {
		;
	}
	return curr % n;
}

int findprev(int curr, int n)
{
	curr--;
	if(curr < 0) {
		curr += n;
	}
	while(nodeList[curr].isValid == false) {
		curr--;
		if(curr < 0) {
			curr += n;
		}
	}
	return curr;
}

bool isEmpty(int n)
{
	int i;
	for(i = 0; i < n; i++) {
		if(nodeList[i].isValid)
			break;
	}
	if(i == n)
		return true;
	else
		return false;
}


void proceedFind(int n, int k, int m)
{
	int curr1 = 0;
	int curr2 = findprev(curr1, n);
	while(!isEmpty(n)) {
		for(int i = 0; i < k - 1; i++) {
			curr1 = findnext(curr1, n);
		}
		for(int i = 0; i < m - 1; i++) {
			curr2 = findprev(curr2, n);
		}
		if(curr1 != curr2)
			printf("%3d%3d", nodeList[curr1].num, nodeList[curr2].num);
		else
			printf("%3d", nodeList[curr1].num);
		nodeList[curr1].isValid = false;
		nodeList[curr2].isValid = false;
		if(isEmpty(n)) {
			break;
		} else {
			printf(",");
		}
		curr1 = findnext(curr1, n);
		curr2 = findprev(curr2, n);
	}
	printf("\n");
}

int main()
{
	freopen("test_input.txt", "r", stdin);
	//freopen("test_output.txt", "w", stdout);
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	while(n != 0) {
		initList(n);
		proceedFind(n, k, m);
		scanf("%d %d %d", &n, &k, &m);
	}
	return 0;
}