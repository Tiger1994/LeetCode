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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		vector<int> left;
		vector<int> right;

		if (root->left) left = postorderTraversal(root->left);
		if (root->right) right = postorderTraversal(root->right);
		
		if (!left.empty()) {
			res = left;
		}
		if (!right.empty()) {
			res.insert(res.end(), right.begin(), right.end());
		}
		res.push_back(root->val);

		return res;
	}

	vector<int> postorderTraversal2(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		stack<TreeNode*> s;
		TreeNode* lastV = NULL;
		TreeNode* tmp = root;

		while (!s.empty() || tmp) {
			if (tmp) {
				s.push(tmp);
				tmp = tmp->left;
			}
			else {
				TreeNode* n = s.top();
				if (n->right && lastV != n->right) {
					tmp = n->right;
				}
				else {
					res.push_back(n->val);
					s.pop();
					lastV = n;
				}
			}
		}

		return res;
	}
};

int main(void) {
	TreeNode* root;
	root = new TreeNode(3);
	Solution mode;

	vector<int> res = mode.postorderTraversal2(root);

	return 0;
}