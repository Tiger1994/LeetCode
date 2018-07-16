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
	void helper(TreeNode *root, int layer, vector<vector<int>> &solutions){
		if (!root) return;
		layer++;
		if (solutions.size() < layer) solutions.push_back({});
		solutions[layer - 1].push_back(root->val);
		if (root->left) helper(root->left, layer, solutions);
		if (root->right) helper(root->right, layer, solutions);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> solutions;
		helper(root, 0, solutions);
		return solutions;
	}
};

int main(void){
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(2);
	//root.right->left = new TreeNode(2);

	Solution model;
	vector<vector<int>> result = model.levelOrder(&root);

	return 0;
}