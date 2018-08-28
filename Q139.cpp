#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool helper(string s, unordered_set<string> wordSet){
		if (s.empty()) return true;
		for (int i = 0; i < s.size(); i++){
			string profix = s.substr(0, i + 1);
			if (wordSet.find(profix) != wordSet.end()){
				string nextS = s;
				nextS.erase(0, i + 1);
				if (helper(nextS, wordSet))
					return true;
			}
		}

		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet;
		for (string word : wordDict)
			wordSet.insert(word);
		
		return helper(s, wordSet);
	}

	bool wordBreak2(string s, vector<string>& wordDict){
			unordered_set<string> wordSet;
			for (string word : wordDict)
				wordSet.insert(word);
			int sLen = s.size();
			vector<bool> record(sLen, false);
			for (int i = 0; i < sLen; i++){
				string subS = s.substr(0, i+1);
				if (wordSet.find(subS) != wordSet.end()){
					record[i] = true;
					continue;
				}
				for (int j = 1; j < i+1; j++){
					string subS = s.substr(i - j + 1, j);
					if (wordSet.find(subS) != wordSet.end())
						record[i] = record[i - j] || record[i];
				}
			}

			return record[sLen - 1];
	}
};

int main(void){
	string s = "applepenapple";
	vector<string> wordDict = { "apple", "pen" };

	Solution model;
	bool res = model.wordBreak2(s, wordDict);

	return 0;
}