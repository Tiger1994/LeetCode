#include<vector>
#include<queue>
#include<deque>
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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main(void){
	TreeNode root(2);
	root.left = new TreeNode(1);
	root.right = new TreeNode(3);
	//root.right->left = new TreeNode(2);

	Solution model;
	int result = model.maxDepth(&root);

	return 0;
}