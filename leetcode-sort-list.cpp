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
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        if(p1 == NULL || p1->next == NULL) {
            return p1;
        }
        if(p1->next->next == NULL) {
        	if(p1->val > p1->next->val) {
				p2 = p1->next;
	            p1->next = NULL;
	            p2->next = p1;
			}
            return p2;
        }
        while(p2 != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        p1 = sortList(head);
        if(p2 != NULL) {
            p2 = sortList(p2);
        }
        ListNode *p3 = NULL;
        ListNode *p4 = NULL;
        int i = 0;
        while(p1 != NULL || p2 != NULL) {
            if(p2 == NULL || p1 != NULL && p1->val < p2->val) {
                if(i == 0) {
                    p4 = p3 = p1;
                    p1 = p1->next;
                    p3->next = NULL;
                } else {
                    p3->next = p1;
                    p3 = p3->next;
                    p1 = p1->next;
                    p3->next = NULL;
                }
            } else {
                if(i == 0) {
                    p4 = p3 = p2;
                    p2 = p2->next;
                    p3->next = NULL;
                } else {
                    p3->next = p2;
                    p3 = p3->next;
                    p2 = p2->next;
                    p3->next = NULL;
                }
            }
            i++;
        }
        return p4;
    }

int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(4);
	p1->next = p2;
	ListNode *p3 = new ListNode(3);
	p2->next = p3;
	
	ListNode *p = sortList(p1);
	while(p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	
	return 0;
}