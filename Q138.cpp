#include<vector>
#include<unordered_map>
using namespace std;
//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		RandomListNode* res = NULL, *curr = NULL, *resCurr = NULL;
		curr = head;
		while (curr){
			if (!res){
				res = new RandomListNode(curr->label);
				resCurr = res;
				curr = curr->next;
				continue;
			}
			else resCurr->next = new RandomListNode(curr->label);
			curr = curr->next;
			resCurr = resCurr->next;
		}

		curr = head;
		resCurr = res;
		while (curr){
			if (curr->random){
				RandomListNode* tmp = head;
				RandomListNode* resTmp = res;
				while (tmp){
					if (tmp->random == curr){
						curr->random = resTmp;
						break;
					}
					tmp = tmp->next;
					resTmp = resTmp->next;
				}
			}

			curr = curr->next;
			resCurr = resCurr->next;
		}

		return res;
	}

	RandomListNode *copyRandomList2(RandomListNode *head){
		if (!head) return NULL;
		unordered_map<RandomListNode*, int> ptrToint;
		unordered_map<int, RandomListNode*> intToptr;
		RandomListNode* res = NULL, *curr = NULL, *resCurr = NULL;
		res = new RandomListNode(head->label);
		resCurr = res;
		curr = head;
		ptrToint[head] = 0;
		intToptr[0] = res;
		int count = 1;
		while (curr->next){
			resCurr->next = new RandomListNode(curr->next->label);			
			curr = curr->next;
			resCurr = resCurr->next;
			intToptr[count] = resCurr;
			ptrToint[curr] = count;			
			count++;
		}

		curr = head;
		resCurr = res;
		while (curr){
			int a = ptrToint[curr->random];
			if (curr->random)
				resCurr->random = intToptr[ptrToint[curr->random]];
			curr = curr->next;
			resCurr = resCurr->next;
		}

		return res;
	}
};

int main(void){
	RandomListNode *head;
	head = new RandomListNode(3);
	//head->next = new RandomListNode(1);

	Solution model;
	RandomListNode* res = model.copyRandomList2(head);

	return 0;
}