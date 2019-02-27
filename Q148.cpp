#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;

		// 找到中间变量
		ListNode *p1 = head, *p2 = head->next;
		while (p2 && p2->next){
			p1 = p1->next;
			p2 = p2->next->next;
		}
		p2 = p1->next;
		p1->next = NULL;
		return mergeTwoLists(sortList(head), sortList(p2));
	}

	ListNode *mergeTwoLists(ListNode *head1, ListNode *head2){
		ListNode *p1 = head1, *p2 = head2;
		ListNode dummy(0);

		ListNode *tail = &dummy;
		while (p1 && p2){
			if (p1->val < p2->val){
				tail->next = p1;
				p1 = p1->next;
			}
			else{
				tail->next = p2;
				p2 = p2->next;
			}
			tail = tail->next;
		}
		if (p1) tail->next = p1;
		if (p2) tail->next = p2;

		return dummy.next;
	}
};

int main(void){
	ListNode *head;
	head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(4);

	Solution mode;
	ListNode *res = mode.sortList(head);

	return 0;
}