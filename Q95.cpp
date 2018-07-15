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
	vector<TreeNode*> generateTrees(int low, int high){
		vector<TreeNode*> res;
		if (low > high){
			res.push_back(NULL);
			return res;
		}
		if (low == high){
			res.push_back( new TreeNode(low));
			return res;
		}

		for (int i = low; i <= high; i++){			
			vector<TreeNode*> leftTree = generateTrees(low, i - 1);
			vector<TreeNode*> rightTree = generateTrees(i + 1, high);
			for (int left = 0; left < leftTree.size(); left++){
				for (int right = 0; right < rightTree.size(); right++){
					TreeNode* root = new TreeNode(i);
					root->left = leftTree[left];
					root->right = rightTree[right];
					res.push_back(root);
				}
			}
		}

		return res;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode *>();
		return generateTrees(1, n);
	}
};

int main(void){
	Solution model;
	vector<TreeNode*> result = model.generateTrees(0);

	return 0;
}