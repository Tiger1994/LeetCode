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
	void helper(TreeNode* root, long long& min, bool& result){
		if (!root) return;
		if (root->left) helper(root->left, min, result);
		if (min >= root->val){
			result = false; return;
		}
		else min = root->val;
		if (root->right) helper(root->right, min, result);
	}
	bool isValidBST(TreeNode* root) {
		bool result = true; long long min = LLONG_MIN;
		helper(root, min, result);

		return result;
	}

	bool isValidBST2(TreeNode* root){
		stack<TreeNode*> records;
		long long min = LLONG_MIN;
		while (root || records.size()){
			while (root){
				records.push(root);
				root = root->left;
			}
			root = records.top(); records.pop();
			if (min >= root->val) return false;
			else min = root->val;
			root = root->right;
		}

		return true;
	}
};

int main(void){
	TreeNode root(1);
	root.left = new TreeNode(1);

	Solution model;
	bool result = model.isValidBST2(&root);

	return 0;
}