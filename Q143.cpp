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
	void reorderList(ListNode* head) {
		vector<ListNode*> nodes;
		ListNode *curr = head;
		while (curr){
			nodes.push_back(curr);
			curr = curr->next;
		}
		int left = 0, right = nodes.size()-1;
		if (right <= 0) return;
		while (left < right){
			nodes[left]->next = nodes[right];
			nodes[right]->next = nodes[left + 1];
			left++;
			right--;
		}
		if (left == right)
			nodes[right]->next = NULL;
		else
			nodes[left]->next = NULL;
	}
};

int main(void){
	ListNode *head;
	head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);

	Solution model;
	model.reorderList(head);

	return 0;
}