#include<vector>
#include<queue>
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
	bool helper(TreeNode *left, TreeNode *right){
		if (!left && !right) return true;
		if (!left || !right) return false;
		return left->val == right->val
			&& helper(left->left, right->right)
			&& helper(left->right, right->left);
	}

	bool isSymmetric(TreeNode* root) {
		return helper(root, root);
	}

	bool isSymmetric2(TreeNode* root){
		queue<TreeNode* > records;
		records.push(root);
		records.push(root);
		while (records.size()){
			TreeNode *left = records.front(); records.pop();
			TreeNode *right = records.front(); records.pop();
			if (!left && !right) continue;
			else if (!left || !right) return false;
			else if (left->val != right->val) return false;
			records.push(left->left);
			records.push(right->right);
			records.push(left->right);
			records.push(right->left);
		}

		return true;
	}
};

int main(void){
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(2);
	//root.right->left = new TreeNode(2);

	Solution model;
	bool result = model.isSymmetric2(&root);

	return 0;
}