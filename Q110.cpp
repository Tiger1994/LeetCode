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
	int maxDep(TreeNode *root){
		if (!root) return 0;
		return max(maxDep(root->left), maxDep(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (abs(maxDep(root->left) - maxDep(root->right) > 1))
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};

int main(void){
	TreeNode root(0);
	root.left = new TreeNode(3);
	root.right = new TreeNode(1);
	root.right->left = new TreeNode(1);
	root.right->left = new TreeNode(1);

	Solution model;
	bool result = model.isBalanced(&root);

	return 0;
}