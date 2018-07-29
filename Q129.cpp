#include<vector>
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
	void helper(TreeNode* root, int num, int &res){
		if (!root) return;
		num = num * 10 + root->val;
		if (!root->left && !root->right){
			res += num;
			return;
		}
		if (root->left) helper(root->left, num, res);
		if (root->right) helper(root->right, num, res);
	}
	int sumNumbers(TreeNode* root) {
		int res = 0;
		helper(root, 0, res);

		return res;
	}
};

int main(void){
	TreeNode* root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution model;
	int res = model.sumNumbers(root);

	return 0;
}