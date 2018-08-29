#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void helper(string s, unordered_set<string> wordSet, string solution, vector<string>& res){
		if (s.empty()){
			res.push_back(solution);
			return;
		}
		for (int i = 0; i < s.size(); i++){
			string profix = s.substr(0, i + 1);
			if (wordSet.find(profix) != wordSet.end()){
				string nextSolution;
				if (solution.empty())
					nextSolution = profix;
				else
					nextSolution = solution + " " + profix;
				string nextS = s;
				nextS.erase(0, i + 1);
				helper(nextS, wordSet, nextSolution, res);
			}
		}
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet;
		for (string word : wordDict)
			wordSet.insert(word);
		vector<string> res;
		helper(s, wordSet, "", res);

		return res;
	}

	vector<string> wordBreak2(string s, vector<string>& wordDict){
		unordered_set<string> wordSet;
		for (string word : wordDict)
			wordSet.insert(word);
		int len = s.size();
		vector<vector<string>> res(len);
		for (int i = len-1; i >= 0; i--){
			string profix = s.substr(i, len - i);
			if (wordSet.find(profix) != wordSet.end()){
				res[i].push_back({ profix });
			}
			for (int j = i + 1; j < len; j++){
				string profix = s.substr(i, j-i);
				if (wordSet.find(profix) != wordSet.end()){
					for (string solution : res[j]){
						res[i].push_back(profix + " " + solution);
					}
				}
			}
		}

		return res[0];
	}
};

int main(void){
	string s = "applepenapple";
	vector<string> wordDict = { "apple", "pen" };

	Solution model;
	vector<string> res = model.wordBreak2(s, wordDict);

	return 0;
}