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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		sum -= root->val;
		if (!root && !sum) return true;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}
};

int main(void){
	TreeNode root(0);
	root.left = new TreeNode(3);
	root.right = new TreeNode(1);
	root.right->left = new TreeNode(1);
	root.right->left = new TreeNode(1);

	Solution model;
	bool result = model.hasPathSum(&root, 4);

	return 0;
}