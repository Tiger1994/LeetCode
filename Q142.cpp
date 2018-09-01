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
    ListNode *detectCycle(ListNode *head) {
		if(head == NULL) return NULL;
        ListNode *fast, *slow;
		fast = head->next, slow = head;
		while(slow && fast && fast->next){
			if(fast == slow) break;
			slow = slow->next;
			fast = fast->next->next;
		}

		if(slow != fast) return NULL;
		slow = head;
		while(slow!=fast){
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
    }
};

int main(void){
	ListNode *head;
	head = new ListNode(0);

	Solution model;
	ListNode *res = model.detectCycle(head);

	return 0;
}