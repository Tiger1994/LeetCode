#include<iostream>
#include<vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL){ return NULL; }
		ListNode* head;
		head = new ListNode(-1);
		ListNode* rear = head;
		int carry_bit = 0;
		while (l1 && l2){
			int temp = l1->val + l2->val + carry_bit;
			rear->next = new ListNode(temp % 10);
			rear = rear->next;
			carry_bit = temp / 10;
			l1 = l1->next;
			l2 = l2->next;
		}

		ListNode* rest;
		if (l1){ rest = l1; }
		else{ rest = l2; }

		while (rest){
			int temp = rest->val + carry_bit;
			rear->next = new ListNode(temp % 10);
			rear = rear->next;
			rest = rest->next;
			carry_bit = temp / 10;			
		}

		if (carry_bit == 1){
			rear->next = new ListNode(1);
		}
		return head->next;
	}
};

int main(void){
	ListNode* l1;
	ListNode* l2;

	l1 = new ListNode(1);
	l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(9);

	Solution model;
	ListNode* result;
	result = model.addTwoNumbers(l1, l2);
	
	return 0;
}