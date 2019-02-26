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
	ListNode* insertionSortList(ListNode* head) {
		ListNode *res = NULL;
		if (!head) return res;

		res = new ListNode(head->val);
		head = head->next;

		while (head) {
			int tmp = head->val;
			ListNode *r = res;
			while (r) {
				if (r->val < tmp) {
					if (!r->next) {
						r->next = new ListNode(tmp);
						break;
					}
					if (r->next && r->next->val >= tmp) {
						ListNode *r_next = r->next;
						r->next = new ListNode(tmp);
						r->next->next = r_next;
						break;
					}
				}
				else {
					ListNode *new_r = new ListNode(tmp);
					new_r->next = r;
					res = new_r;
					break;
				}
				r = r->next;
			}
			head = head->next;
		}

		return res;
	}

	ListNode *insertionSortList2(ListNode *head) {
		if (!head || !head->next) return head;

		ListNode *res = NULL;
		while (head) {
			ListNode *tmp_head = head;
			head = head->next;

			ListNode **tmp_res = &res;
			while (*tmp_res && (*tmp_res)->val < tmp_head->val) {
				tmp_res = &((*tmp_res)->next);
			}
			tmp_head->next = *tmp_res;
			*tmp_res = tmp_head;
		}
		return res;
	}
};

int main(void) {
	ListNode *head;
	head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(4);

	Solution mode;
	ListNode *res = mode.insertionSortList2(head);

	return 0;
}