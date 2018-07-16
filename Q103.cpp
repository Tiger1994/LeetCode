#include<vector>
#include<queue>
#include<deque>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		deque<TreeNode*> records;
		if(root) records.push_front(root);
		TreeNode *last = root;
		int layer = 1;
		while (records.size()){
			TreeNode *curr;
			if (vv.size() < layer) vv.push_back({});
			if (layer % 2){
				curr = records.front();
				records.pop_front();
				vv[layer - 1].push_back(curr->val);
				if (curr->left) records.push_back(curr->left);
				if (curr->right) records.push_back(curr->right);
			}
			else{
				curr = records.back();
				records.pop_back();
				vv[layer - 1].push_back(curr->val);
				if (curr->right) records.push_front(curr->right);
				if (curr->left) records.push_front(curr->left);
			}
			if (last == curr && records.size()){
				layer++;
				last = layer % 2 ? records.back() : records.front();
			}
		}
		return vv;
	}

	vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
		vector<vector<int>> vv;
		queue<TreeNode*> records;
		if (root) records.push(root);
		TreeNode *last = root;
		int layer = 1;
		while (records.size()){
			TreeNode *curr = records.front();
			records.pop();
			if (vv.size() < layer) vv.push_back({});
			vv[layer - 1].insert(layer % 2 ? vv[layer - 1].end() : vv[layer - 1].begin(), curr->val);
			if (curr->left) records.push(curr->left);
			if (curr->right) records.push(curr->right);
			if (curr == last && records.size()){
				layer++;
				last = records.back();
			}
		}
		return vv;
	}
};

int main(void){
	TreeNode root(2);
	root.left = new TreeNode(1);
	root.right = new TreeNode(3);
	//root.right->left = new TreeNode(2);

	Solution model;
	vector<vector<int>> result = model.zigzagLevelOrder2(&root);

	return 0;
}