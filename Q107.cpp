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
	void helper(TreeNode* root, int layer, vector<vector<int>>& result){
		if (!root) return;
		layer++;
		if (result.size() < layer){
			if (result.size() == 0) result.push_back({});
			else result.insert(result.begin(), {});
		}
		int idx = result.size() - layer;
		result[idx].push_back(root->val);
		if (root->left) helper(root->left, layer, result);
		if (root->right) helper(root->right, layer, result);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		helper(root, 0, result);

		return result;
	}

	void helper2(TreeNode* root, int layer, vector<vector<int>>& result){
		if (!root) return;
		layer++;
		if (result.size() < layer) result.push_back({});
		result[layer-1].push_back(root->val);
		if (root->left) helper2(root->left, layer, result);
		if (root->right) helper2(root->right, layer, result);
	}

	vector<vector<int>> levelOrderBottom2(TreeNode* root) {
		vector<vector<int>> temp;
		helper2(root, 0, temp);

		vector<vector<int>> result;
		for (int i = temp.size()-1; i>=0; i--)
			result.push_back(temp[i]);

		return result;
	}
};

int main(void){
	TreeNode root(3);
	root.left = new TreeNode(9);
	root.right = new TreeNode(20);
	root.right->left = new TreeNode(15);
	root.right->right = new TreeNode(7);

	Solution model;
	vector<vector<int>> result = model.levelOrderBottom2(&root);

	return 0;
}