#include<queue>
using namespace std;
//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		queue<TreeLinkNode *> q;
		q.push(root);
		TreeLinkNode *last = root;
		while (q.size()){
			TreeLinkNode* curr = q.front();
			q.pop();
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
			if (last == curr){
				if (q.size()) last = q.back();
			}
			else{
				curr->next = q.front();
			}
		}
	}

	void connect2(TreeLinkNode *root){
		if (!root) return;
		while (root){
			TreeLinkNode *next = NULL;
			TreeLinkNode *pre = NULL;
			next = root;
			while (next){
				if (next->left) { next = next->left; break; }
				if (next->right){ next = next->right; break; }
				next = next->next;
			}

			while (root){
				if (root->left){
					if (pre) pre->next = root->left;
					pre = root->left;
				}
				if (root->right){
					if (pre) pre->next = root->right;
					pre = root->right;
				}
				root = root->next;
			}

			root = next;
		}
	}
};

int main(void){
	TreeLinkNode root(0);
	root.left = new TreeLinkNode(1);
	root.right = new TreeLinkNode(1);

	Solution model;
	model.connect2(&root);

	return 0;
}