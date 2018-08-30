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
	bool hasCycle(ListNode *head) {
		ListNode *curr;
		curr = head;
		while (curr){
			if (curr->next == head) return true;
			ListNode *pre = curr;
			curr = curr->next;
			pre->next = head;
		}

		return false;
	}
};

int main(void){
	ListNode *head;
	head = new ListNode(0);
	head->next = head;
	Solution model;
	bool res = model.hasCycle(head);

	return 0;
}