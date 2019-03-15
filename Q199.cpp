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
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> d;
		vector<int> res;
		TreeNode *last = root;
		d.push(root);
		while (root) {
			if (root->left) d.push(root->left);
			if (root->right) d.push(root->right);
			if (root == last) { res.push_back(root->val); last = d.back(); }
			d.pop();
			if(!d.empty()) root = d.front();
			else root = NULL;
		}
		return res;
	}
};

int main(void) {
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution mode;
	vector<int> res = mode.rightSideView(root);
	return 0;
}