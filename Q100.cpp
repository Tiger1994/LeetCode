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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!q && !p) return true;
		else if (q && p && q->val == p->val){
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else return false;
	}
};

int main(void){
	TreeNode root(3);
	root.left = new TreeNode(1);
	root.right = new TreeNode(4);
	root.right->left = new TreeNode(2);

	Solution model;
	bool result = model.isSameTree(&root, &root);

	return 0;
}