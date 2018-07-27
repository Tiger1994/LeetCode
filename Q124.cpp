#include<vector>
#include<algorithm>
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
	int maxPathSum(TreeNode *root, int &maxSum){
		int maxLeft = 0, maxRight = 0;
		if (root->left) maxLeft = maxPathSum(root->left, maxSum);
		if (root->right) maxRight = maxPathSum(root->right, maxSum);
		int maxBranch = maxLeft > maxRight ? maxLeft + root->val : maxRight + root->val;
		maxSum = max(maxSum, root->val);
		maxSum = max(maxSum, maxLeft);
		maxSum = max(maxSum, maxRight);
		maxSum = max(maxSum, maxBranch);
		maxSum = max(maxSum, maxLeft + maxRight + root->val);
		return maxBranch;
	}

	int maxPathSum(TreeNode* root) {
		int maxSum = INT_MIN;
		maxPathSum(root, maxSum);
		return maxSum;
	}
};

int main(void){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution model;
	int result = model.maxPathSum(root);

	return 0;
}