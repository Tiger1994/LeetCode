#include<vector>
#include<string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * merge2(ListNode *l1, ListNode *l2){
		ListNode result(0), *curr;
		curr = &result;
		while (l1 && l2){
			if (l1->val < l2->val){
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

	ListNode* mergeKLists(vector<ListNode*>& lists) {	
		if (lists.size() == 0) return NULL;
		while (lists.size() > 1){
			vector<ListNode*> temp_lists;
			for (int i = 0; i < lists.size() / 2; i++){
				ListNode* temp = merge2(lists[2*i], lists[2*i + 1]);
				temp_lists.push_back(temp);
			}

			if (lists.size() % 2) temp_lists.push_back(lists[lists.size() - 1]);
			lists = temp_lists;
		}

		return lists[0];
	}
};

int main(void){
	vector<ListNode*> lists;
	for (int i = 0; i < 4; i++){
		ListNode *head, *curr;
		head = new ListNode(0);
		curr = head;
		for (int j = 0; j < 3; j++){
			curr->next = new ListNode(j + 1);
			curr = curr->next;
		}
		lists.push_back(head);
	}
	lists[0] = NULL;
	lists[2] = NULL;

	Solution model;
	ListNode* result = model.mergeKLists(lists);

	return 0;
}