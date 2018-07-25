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
	void helper(TreeNode *root, int sum, vector<int>& solution, vector<vector<int>>& vvInt){
		if (!root) return;
		sum -= root->val;
		solution.push_back(root->val);
		if (!root->left && !root->right && !sum){
			vvInt.push_back(solution);
			return;
		}
		if (root->left){
			helper(root->left, sum, solution, vvInt);
		}
		if (root->right){
			helper(root->right, sum, solution, vvInt);
		}
		solution.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> vvInt;
		helper(root, sum, {}, vvInt);
		return vvInt;
	}
};

int main(void){
	TreeNode root(0);
	root.left = new TreeNode(3);
	root.right = new TreeNode(1);
	root.right->left = new TreeNode(1);
	root.right->left = new TreeNode(1);

	Solution model;
	vector<vector<int>> result = model.pathSum(&root, 4);

	return 0;
}