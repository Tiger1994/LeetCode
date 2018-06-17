#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode feakHead(0), *curr;
		feakHead.next = head; head = &feakHead; curr = head;
		
		while (curr->next && curr->next->next){
			ListNode *temp = curr->next;
			curr->next = curr->next->next;
			temp->next = curr->next->next;
			curr->next->next = temp;
			curr = curr->next->next;
		}

		return feakHead.next;
	}
};

int main(void){
	ListNode *head, *curr;
	head = new ListNode(0); curr = head;

	for (int i = 0; i < 4; i++){
		curr->next = new ListNode(i + 1);
		curr = curr->next;
	}

	Solution model;
	ListNode *result = model.swapPairs(head);

	return 0;
}