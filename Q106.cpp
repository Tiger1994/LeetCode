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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int len = inorder.size();
		if (len == 0) return NULL;

		int val = postorder[len - 1];
		int right = len - 1;
		while (inorder[right] != val) right--;
		TreeNode *root = new TreeNode(val);
		vector<int> inorderLeft(inorder.begin(), inorder.begin() + right);
		vector<int> postorderLeft(postorder.begin(), postorder.begin() + right);
		root->left = buildTree(inorderLeft, postorderLeft);
		vector<int> inorderRight(inorder.begin() + right+1, inorder.end());
		vector<int> postorderRight(postorder.begin() + right, postorder.end() - 1);
		root->right = buildTree(inorderRight, postorderRight);

		return root;
	}
};

int main(void){
	vector<int> inorder = { 9, 3, 15, 20, 7 };
	vector<int> postorder = { 9, 15, 7, 20, 3 };

	Solution model;
	TreeNode *result = model.buildTree(inorder, postorder);

	return 0;
}