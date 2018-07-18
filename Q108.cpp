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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		int mid = nums.size() / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		vector<int> leftNums( nums.begin(), nums.begin() + mid );
		vector<int> rightNums(nums.begin() + mid + 1, nums.end());
		root->left = sortedArrayToBST(leftNums);
		root->right = sortedArrayToBST(rightNums);

		return root;
	}
};

int main(void){
	vector<int> nums = { -10, -3, 0, 5, 9 };

	Solution model;
	TreeNode* result = model.sortedArrayToBST(nums);

	return 0;
}