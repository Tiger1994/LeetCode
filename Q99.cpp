#include<vector>
#include<stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void helper(TreeNode* root, int *&val, int *&first, int *&second){
		if (!root) return;

		if (root->left) helper(root->left, val, first, second);

		if (!val) val = &root->val;		
		else if (root->val < *val && !first) {
			first = val; second = &root->val;
		}
		else if (root->val < *val) {
			second = &root->val; return;
		}
		val = &root->val;

		if (root->right) helper(root->right, val, first, second);
	}

	void recoverTree(TreeNode* root) {
		int *val = NULL, *first = NULL, *second = NULL;
		helper(root, val, first, second);
		int temp = *first;
		*first = *second;
		*second = temp;
	}
};

int main(void){
	TreeNode root(3);
	root.left = new TreeNode(1);
	root.right = new TreeNode(4);
	root.right->left = new TreeNode(2);

	Solution model;
	model.recoverTree(&root);

	return 0;
}