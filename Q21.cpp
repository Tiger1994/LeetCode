#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode result(0), *curr;
		curr = &result;

		while (l1 && l2){
			if (l1->val <= l2->val){
				curr->next = l1;
				curr = curr->next;
				l1 = l1->next;
			}
			else{
				curr->next = l2;
				curr = curr->next;
				l2 = l2->next;
			}
		}

		curr->next = l1 ? l1 : l2;

		return result.next;
	}
};

int main(void){
	ListNode *l1, *l2, *curr1, *curr2;
	l1 = new ListNode(0);
	l2 = new ListNode(0);
	curr1 = l1; curr2 = l2;
	for (int i = 0; i < 2; i++){
		ListNode* temp1 = new ListNode(i + 1);
		ListNode* temp2 = new ListNode(i + 1);
		curr1->next = temp1; curr2->next = temp2;
		curr1 = curr1->next; curr2 = curr2->next;
	}

	Solution model;
	ListNode* result = model.mergeTwoLists(l1, l2);

	return 0;
}