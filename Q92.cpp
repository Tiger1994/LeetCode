#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode feakHead = ListNode(0); feakHead.next = head;
		head = &feakHead;
		ListNode *curr = head;
		ListNode *currB = NULL;
		ListNode *startR = NULL;
		ListNode *endR = NULL;
		while (curr->next){
			m--; n--;
			if (m <= 0){
				if (!currB) currB = curr;
				if (!startR) startR = new ListNode(curr->next->val);
				if (!endR) endR = startR;
				else{
					ListNode *temp = new ListNode(curr->next->val);
					temp->next = startR;
					startR = temp;
				}
			}
			if (n <= 0) break;
			curr = curr->next;
		}
		endR->next = curr->next->next;
		currB->next = startR;		

		return head->next;
	}
};

int main(void){
	ListNode head(1), *curr; curr = &head;
	for (int i = 0; i < 5; i++){
		curr->next = new ListNode(i + 1);
		curr = curr->next;
	}

	Solution model;
	ListNode* result = model.reverseBetween(&head, 1, 1);

	return 0;
}