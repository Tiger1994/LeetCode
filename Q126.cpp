#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

class Solution {
private:
	struct TreeNode{
		string val;
		vector<TreeNode*> next;
		TreeNode(string x) : val(x){}
	};

public:
	vector<string> changeOne(string s, vector<string>& list){
		vector<string> res;
		vector<string> left;
		for (int i = 0; i < list.size(); i++){
			int diffCount = 0;
			for (int j = 0; j < s.size(); j++){
				if (s[j] != list[i][j]) diffCount++;
			}
			if (diffCount == 1) res.push_back(list[i]);
			else left.push_back(list[i]);
		}
		list = left;
		return res;
	}

	TreeNode *genTree(string begin,vector<string> list){
		TreeNode *root = new TreeNode(begin);
		vector<string> nextList = changeOne(begin, list);
		if (nextList.size() == 0) return root;
		for (int i = 0; i < nextList.size(); i++){
			root->next.push_back({});
			root->next[i] = genTree(nextList[i], list);
		}
		return root;
	}

	void DFS(TreeNode *root, string end, vector<string> solution, vector<vector<string>>& res){
		if (!root) return;
		solution.push_back(root->val);
		if (root->val == end){
			res.push_back(solution);
			return;
		}

		for (int i = 0; i < root->next.size(); i++){
			DFS(root->next[i], end, solution, res);
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		TreeNode *root = genTree(beginWord, wordList);
		vector<vector<string>> res;
		DFS(root, endWord, {}, res);
		int minLen = INT_MAX;
		for (int i = 0; i < res.size(); i++){
			minLen = min(minLen, int(res[i].size()));
		}
		vector<vector<string>> temp;
		for (int i = 0; i < res.size(); i++){
			if (res[i].size() == minLen)
				temp.push_back(res[i]);
		}
		return temp;
	}

	vector<TreeNode*> getNext(TreeNode* root, vector<TreeNode*> nodes){
		vector<TreeNode*> nextNodes;
		vector<TreeNode*> leftNodes;
		for (int i = 0; i < nodes.size(); i++){
			int diffCount = 0;
			for (int j = 0; j < root->val.size(); j++){
				if (root->val[j] != nodes[i]->val[j])
					diffCount++;
			}
			if (diffCount == 1) nextNodes.push_back(nodes[i]);
			else leftNodes.push_back(nodes[i]);
		}
		return nextNodes;
	}

	void genTree2(TreeNode *root, vector<TreeNode*> nodes){
		vector<TreeNode*> record;
		vector<TreeNode*> restNodes;
		set<TreeNode*> usedNodes;
		for (int i = 0; i < nodes.size(); i++)
			if (root->val != nodes[i]->val)
				usedNodes.insert(nodes[i]);

		copy(usedNodes.begin(), usedNodes.end(), back_inserter(restNodes));
		record.push_back(root);
		TreeNode *last = root;

		while (record.size() && restNodes.size()){
			TreeNode *curr = record.front();
			record.erase(record.begin());
			vector<TreeNode*> nextNodes = getNext(curr, restNodes);
			
			curr->next = nextNodes;
			for (int i = 0; i < nextNodes.size(); i++){
				if (find(record.begin(), record.end(), nextNodes[i]) == record.end())
					record.push_back(nextNodes[i]);
				usedNodes.erase(nextNodes[i]);
			}

			if (curr == last){
				if (restNodes.size() == usedNodes.size()) return;
				last = record.back();
				restNodes = {};
				copy(usedNodes.begin(), usedNodes.end(), back_inserter(restNodes));
			}
		}
	}

	void DFS2(TreeNode *root, string end, vector<string> solution, vector<vector<string>>& res, int layer, int depth){
		layer++;
		if (layer > depth) return;
		if (!root) return;
		solution.push_back(root->val);
		if (root->val == end){
			res.push_back(solution);
			return;
		}

		for (int i = 0; i < root->next.size(); i++){
			DFS2(root->next[i], end, solution, res, layer, depth);
		}
	}

	vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList){
		vector<TreeNode*> nodes;
		for (int i = 0; i < wordList.size(); i++){
			nodes.push_back(new TreeNode(wordList[i]));
		}

		TreeNode *root = new TreeNode(beginWord);
		genTree2(root, nodes);

		vector<vector<string>> res;
		DFS2(root, endWord, {}, res, 0, nodes.size());
		int minLen = INT_MAX;
		for (int i = 0; i < res.size(); i++){
			minLen = min(minLen, int(res[i].size()));
		}
		vector<vector<string>> temp;
		for (int i = 0; i < res.size(); i++){
			if (res[i].size() == minLen)
				temp.push_back(res[i]);
		}

		return temp;
	}
};

int main(void){
	string begin = "red";
	string end = "tax";
	vector<string> list = { "ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };

	Solution model;
	vector<vector<string>> res = model.findLadders2(begin, end, list);

	return 0;
}