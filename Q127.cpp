#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
private:
	struct TreeNode{
		string val;
		vector<TreeNode*> next;
		TreeNode(string x) : val(x){}
	};

public:
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

	int ladderLength(string beginWord, string endWord, vector<string>& wordList){
		vector<TreeNode*> nodes;
		for (int i = 0; i < wordList.size(); i++){
			nodes.push_back(new TreeNode(wordList[i]));
		}

		TreeNode *root = new TreeNode(beginWord);
		genTree2(root, nodes);

		vector<vector<string>> res;
		DFS2(root, endWord, {}, res, 0, nodes.size());
		if (res.size() == 0) return 0;
		int minLen = INT_MAX;
		for (int i = 0; i < res.size(); i++){
			minLen = min(minLen, int(res[i].size()));
		}
		return  minLen;
	}

	int ladderLength2(string beginWord, string endWord, vector<string>& wordList){
		unordered_set<string> visited;
		unordered_set<string> unvisited(wordList.begin(), wordList.end());
		visited.insert(beginWord);
		int res = 1;
		while (visited.count(endWord) == 0){
			unordered_set<string> newU = unvisited;
			unordered_set<string> newV = visited;
			for (string v : visited){
				for (string u : unvisited){
					int count = 0;
					for (int i = 0; i < v.size(); i++)
						if (v[i] != u[i])
							count++;
					if (count == 1){
						newV.insert(u);
						newU.erase(u);
					}
				}
			}
			if (newV.size() == visited.size()) return 0;
			unvisited = newU;
			visited = newV;
			res++;
		}

		return res;
	}
};

int main(void){
	string begin = "hit";
	string end = "cog";
	vector<string> list = { "hot", "dot", "dog", "lot", "log", "cog" };

	Solution model;
	int res = model.ladderLength2(begin, end, list);

	return 0;
}