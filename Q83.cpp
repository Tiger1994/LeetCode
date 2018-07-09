#include<vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode feakHead(0);
		feakHead.next = head; head = &feakHead;
		ListNode *curr = head;
		while (curr->next){
			if (curr->next->next && curr->next->val == curr->next->next->val){
				curr->next = curr->next->next;
			}
			else curr = curr->next;
		}

		return head->next;
	}
};

int main(void){
	ListNode head(1), *curr;
	curr = &head;
	for (int i = 0; i < 1; i++){
		curr->next = new ListNode(i + 1);
		curr = curr->next;
	}

	Solution model;
	ListNode *result = model.deleteDuplicates(&head);

	return 0;
}