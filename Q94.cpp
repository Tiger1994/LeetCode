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
	void inorder(TreeNode *t, vector<int> &result){
		if (!t) return;
		inorder(t->left, result);
		result.push_back(t->val);
		inorder(t->right, result);		
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inorder(root, result);
		return result;
	}

	vector<int> inorderTraversal2(TreeNode* root){
		stack<TreeNode*> records;
		vector<int> result;
		TreeNode *curr = root;
		while (curr || !records.empty()){
			while (curr){
				records.push(curr);
				curr = curr->left;
			}
			curr = records.top(); records.pop();
			result.push_back(curr->val);
			curr = curr->right;
		}

		return result;
	}
};

int main(void){
	TreeNode root(1);
	root.right = new TreeNode(2);
	root.right->left = new TreeNode(3);

	Solution model;
	vector<int> result = model.inorderTraversal2(&root);

	return 0;
}