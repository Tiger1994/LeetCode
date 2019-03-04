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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pA, *pB;
		int lenA = 0, lenB = 0;
		pA = headA, pB = headB;
		while (pA) {
			lenA++;
			pA = pA->next;
		}
		while (pB) {
			lenB++;
			pB = pB->next;
		}
		pA = headA, pB = headB;
		while (pA && pB) {
			if (lenA > lenB) {
				lenA--;
				pA = pA->next;
				continue;
			}
			else if (lenA < lenB) {
				lenB--;
				pB = pB->next;
				continue;
			}
			else {
				if (pA == pB) return pA;
				else {
					pA = pA->next;
					pB = pB->next;
				}
			}
		}
		return NULL;
	}
};

int main(void) {
	ListNode *headA, *headB;
	headA = new ListNode(0);
	headB = new ListNode(1);

	Solution mode;
	ListNode *res = mode.getIntersectionNode(headA, headB);

	return 0;
}