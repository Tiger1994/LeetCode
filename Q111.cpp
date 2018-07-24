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
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (root->left && root->right)
			return min(minDepth(root->left), minDepth(root->right)) + 1;
		else if (root->left)
			return minDepth(root->left) + 1;
		else if (root->right)
			return minDepth(root->right) + 1;
		return 1;
	}
};

int main(void){
	TreeNode root(0);
	root.left = new TreeNode(3);
	root.right = new TreeNode(1);
	root.right->left = new TreeNode(1);
	root.right->left = new TreeNode(1);

	Solution model;
	int result = model.minDepth(&root);

	return 0;
}