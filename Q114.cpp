#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		if (root->left && root->left->left)
			flatten(root->left);
		else if (root->left){
			TreeNode* oldRight = root->right, *currRight = root->left;
			root->right = root->left;
			while (currRight->right) currRight = currRight->right;
			currRight->right = oldRight;
			root->left = NULL;
		}
		flatten(root->right);
	}
};

int main(void){
	TreeNode root(0);
	root.left = new TreeNode(3);
	root.right = new TreeNode(1);
	root.right->left = new TreeNode(1);
	root.right->left = new TreeNode(1);

	Solution model;
	model.flatten(&root);

	return 0;
}