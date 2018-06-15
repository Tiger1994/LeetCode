#include<iostream>
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
	ListNode* removeNthFromEnd_1(ListNode* head, int n) {
		int idx = 0;
		vector<ListNode*> nodes;
		ListNode* temp = head;
		while (temp){
			nodes.push_back(temp);
			temp = temp->next;
		}

		int list_len = nodes.size();
		if (list_len == 1) return NULL;
		else if (list_len == 2){
			if (n == 1){
				delete head->next;
				head->next = NULL;
				return head;
			}
			else{
				ListNode* temp = head;
				head = head->next;
				delete temp;
				return head;
			}
		}

		if (list_len == n){
			ListNode* temp = head;
			head = head->next;
			delete temp;
			return head;
		}

		ListNode* q = nodes[list_len-n-1];
		ListNode* p = q->next;
		q->next = p->next;
		delete p;

		return head;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n){
		ListNode *feakhead;
		feakhead = new ListNode(-1);
		feakhead->next = head;
		head = feakhead;

		ListNode *p1, *p2;
		p1 = p2 = head;
		for (int i = 0; i < n; i++){
			p1 = p1->next;
		}

		while (p1->next){
			p1 = p1->next;
			p2 = p2->next;
		}

		ListNode* temp;
		temp = p2->next;
		p2->next = p2->next->next;
		delete temp;

		return head->next;
	}
};

int main(void){
	ListNode *head, *curr;
	int n = 1;
	head = new ListNode(1);
	//curr = head;
	//for (int i = 1; i < 3; i++){
	//	ListNode* temp;
	//	temp = new ListNode(i+1);
	//	curr->next = temp;
	//	curr = curr->next;
	//}


	Solution model;
	ListNode* result = model.removeNthFromEnd(head, n);

	return 0;
}