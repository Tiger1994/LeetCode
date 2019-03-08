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

class BSTIterator {
public:
	vector<int> nums;
	BSTIterator(TreeNode* root) {
		initN(root);
	}

	void initN(TreeNode *root) {
		if (!root) return;
		if (root->left) initN(root->left);
		nums.push_back(root->val);
		if (root->right) initN(root->right);
	}

	/** @return the next smallest number */
	int next() {
		int tmp = nums[0];
		nums.erase(nums.begin());
		return tmp;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return nums.size();
	}
};

class BSTIterator2{
public:
	BSTIterator2(TreeNode* root) {
		addS(root);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *tmp = s.top();
		s.pop();
		if (tmp->right) addS(tmp->right);
		return tmp->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}
private:
	stack<TreeNode *> s;
	void addS(TreeNode *root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}
};

int main(void) {
	TreeNode *root;
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	BSTIterator2 mode(root);
	bool a = mode.hasNext();
	int b = mode.next();

	return 0;
}