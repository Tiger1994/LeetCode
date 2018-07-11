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
	ListNode* partition(ListNode* head, int x) {
		bool notSort = true;
		while (notSort){
			notSort = false;
			int findEnd = 0, trueEnd = 0;
			ListNode *curr = head;
			while (curr){
				if (curr && curr->next && curr->val >= x && curr->next->val < x){
					int temp = curr->val;
					curr->val = curr->next->val;
					curr->next->val = temp;
					notSort = true;
				}
				curr = curr->next;
			}
		}

		return head;
	}

	ListNode* partition2(ListNode* head, int x){
		ListNode feakHead(0); feakHead.next = head; head = &feakHead;
		ListNode *bigPos = NULL, *curr = head;
		while (curr && curr->next){
			if (curr->next->val >= x && !bigPos){
				bigPos = curr;
			}
			else if (curr->next->val < x && bigPos){
				ListNode *bigNext = bigPos->next;
				bigPos->next = new ListNode(curr->next->val);
				curr->next = curr->next->next;
				bigPos->next->next = bigNext;
				bigPos = bigPos->next;
			}

			curr = curr->next;
		}

		return head->next;
	}
};

int main(void){
	ListNode head(1), *curr;
	curr = &head;
	vector<int> values = { 1, 4, 3, 2, 5, 2 };
	for (int i = 0; i < values.size(); i++){
		curr->next = new ListNode(values[i]);
		curr = curr->next;
	}

	Solution model;
	ListNode *result = model.partition2(&head, 3);

	return 0;
}