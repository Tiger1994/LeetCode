#include<vector>
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root != NULL) {
			res.push_back(root->val);
		}
		else return res;

		vector<int> left = preorderTraversal(root->left);
		vector<int> right = preorderTraversal(root->right);

		if(left.size() > 0) res.insert(res.end(), left.begin(), left.end());
		if (right.size() > 0) res.insert(res.end(), right.begin(), right.end());

		return res;
	}

	vector<int> preorderTraversal2(TreeNode* root) {
		vector<int> res;
		vector<TreeNode*> s;
		TreeNode* tmp = root;

		while (!s.empty() || tmp) {
			while (tmp) {
				res.push_back(tmp->val);
				s.push_back(tmp->right);
				tmp = tmp->left;
			}

			tmp = s.back();
			s.pop_back();
		}

		return res;
	}
};

int main(void) {
	TreeNode* root;
	root = new TreeNode(3);
	Solution mode;

	vector<int> res = mode.preorderTraversal2(root);

	return 0;
}