#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} NODE, *NODEPTR;

NODEPTR buildLL(void)
{
	NODEPTR head = NULL;
	NODEPTR curr = NULL;
	NODEPTR tmp = NULL;
	for(int i = 0; i < 5; i++) {
		if(i < 3) {
			tmp = (NODEPTR) malloc(sizeof(NODE));
			tmp->data = i;
			tmp->next = NULL;
			if(i == 0) {
				head = curr = tmp;
			} else {
				curr->next = tmp;
				curr = tmp;
			}
		} else {
			tmp = (NODEPTR) malloc(sizeof(NODE));
			tmp->data = 4 - i;
			tmp->next = NULL;
			curr->next = tmp;
			curr = tmp;
		}
	}
	return head;
}


int isPalindromeRecurse(NODEPTR head, int len, NODEPTR *nextp)
{
	if(head == NULL) {
		return 0;
	} else if(len == 1) {
		(*nextp) = head->next;
		return 1;
	} else if(len == 2) {
		(*nextp) = head->next->next;
		return head->data == head->next->data;
	}
	NODEPTR *end = NULL;
	int re = isPalindromeRecurse(head->next, len - 2, end);
	if(re) {
		int result = head->data == (*end)->data;
		(*nextp) = (*end)->next;
		return result;
	} else {
		return re;
	}
}

int main()
{
	NODEPTR head = buildLL();
	NODEPTR *tmp = NULL;
	int result = isPalindromeRecurse(head, 5, tmp);
	printf("%d\n", result);
	
	return 0;
}