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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		int val = preorder[0];

		int left = 0;
		while (inorder[left] != val) left++;
		TreeNode *root = new TreeNode(val);
		vector<int> preorderLeft(preorder.begin()+1, preorder.begin() + left+1);
		vector<int> inorderLeft(inorder.begin(), inorder.begin() + left);
		root->left = buildTree(preorderLeft, inorderLeft);
		vector<int> preorderRight(preorder.begin() + left+1, preorder.end());
		vector<int> inorderRight(inorder.begin() + left+1, inorder.end());
		root->right = buildTree(preorderRight, inorderRight);
		
		return root;
	}

	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder, vector<int> p){
		if (p[0] < 0 || p[2] < 0 || p[1] < p[0] || p[3] < p[2] || p[0] >= preorder.size() || p[2] >= inorder.size())
			return NULL;
		int val = preorder[p[0]];
		int left = p[2];
		while (inorder[left] != val) left++;
		TreeNode *root = new TreeNode(val);
		vector<int> pLeft = p;
		pLeft[0]++;
		pLeft[1] = p[0]+left-p[2];
		pLeft[3] = left-1;
		root->left = buildTree2(preorder, inorder, pLeft);
		vector<int> pRight = p;
		pRight[0] += left-p[2] + 1;
		pRight[2] = left + 1;
		root->right = buildTree2(preorder, inorder, pRight);

		return root;
	}

	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder){
		vector<int> p;
		p.push_back(0);
		p.push_back(preorder.size() - 1);
		p.push_back(0);
		p.push_back(inorder.size() - 1);
		return buildTree2(preorder, inorder, p);
	}
};

int main(void){
	vector<int> preorder = { 1, 2, 3 };
	vector<int> inorder = { 2, 3, 1};

	Solution model;
	TreeNode *result = model.buildTree2(preorder, inorder);

	return 0;
}