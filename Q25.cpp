#include<iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1) return head;
		ListNode feakHead(0); feakHead.next = head;
		ListNode *curr; curr = &feakHead;

		ListNode *start = &feakHead;
		int d_count = 0;
		while (curr->next){
			ListNode *rTail, *rHead, *tCurr;
			rTail = new ListNode(curr->next->val); rHead = rTail;
			d_count++;
			int count = 1;
			curr = curr->next; tCurr = curr;

			while (curr->next && count < k){
				ListNode* temp = new ListNode(curr->next->val);
				temp->next = rHead;
				rHead = temp;
				curr = curr->next;
				count++;
				d_count++;
			}

			if (count <= k - 1){
				while (rHead){
					ListNode *temp = rHead;
					rHead = rHead->next;
					delete temp;
					d_count--;
				}
			}
			else{
				start->next = rHead;
				rTail->next = curr->next;
				start = rTail;
			}
		}

		//while (head && d_count > 0){
		//	ListNode *temp = head;
		//	head = head->next;
		//	delete temp;
		//	d_count--;
		//}

		return feakHead.next;
	}
};

int main(void){
	ListNode *head, *curr;
	int k = 3;
	head = new ListNode(1); curr = head;
	for (int i = 0; i < 4; i++){
		curr->next = new ListNode(i + 2);
		curr = curr->next;
	}

	Solution model;
	ListNode *result = model.reverseKGroup(head, k);

	return 0;
}
