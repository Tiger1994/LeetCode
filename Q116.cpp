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
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
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
		if (root->left) root->left->next = root->right;
		if (root->right) root->right = root->next ? root->next->left : NULL;
		connect(root->left);
		connect(root->right);
	}
};

int main(void){
	TreeLinkNode root(0);
	root.left = new TreeLinkNode(1);
	root.right = new TreeLinkNode(1);

	Solution model;
	model.connect(&root);

	return 0;
}