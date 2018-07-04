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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return NULL;
		ListNode *left = NULL, *right = NULL, *leftCurr = NULL, *rightCurr = NULL;
		int count = 0; ListNode *curr = head; int listLen = 0;
		while (curr){
			listLen++; curr = curr->next;}

		curr = head; k = k % listLen;
		while (curr){
			if (count < listLen-k){
				if (!left){
					left = new ListNode(curr->val); leftCurr = left;
				}else{
					leftCurr->next = new ListNode(curr->val);
					leftCurr = leftCurr->next;}
			}else{
				if (!right){
					right = new ListNode(curr->val); rightCurr = right;
				}else{
					rightCurr->next = new ListNode(curr->val);
					rightCurr = rightCurr->next;}}
			curr = curr->next; count++;}

		if (right){
			rightCurr->next = left;	return right;}
		else return left;
	}

	ListNode* rotateRight_2(ListNode* head, int k){
		if (!head || k<=0) return head;
		ListNode *p = head; int listLen = 1;
		while (p->next){
			listLen++; p = p->next;}

		p->next = head; k = listLen - k%listLen;
		while (k > 0) { 
			p = p->next; k--;}

		head = p->next; p->next = NULL;

		return head;
	}
};

int main(void){
	vector<int> values = { 1, 2, 3, 4, 5 };
	int k = 2;
	ListNode head(1), *curr; curr = &head;
	for (int i = 1; i < values.size(); i++){
		curr->next = new ListNode(values[i]);
		curr = curr->next;
	}

	ListNode head2(1);

	Solution model;
	ListNode* result = model.rotateRight_2(&head, k);

	return 0;
}