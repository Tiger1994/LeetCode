#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool recurse(string s1, int start1, int len, string s2, int start2){
		if (len == 1) return s1[start1] == s2[start2];
		for (int i = 1; i < len; i++){
			if ((recurse(s1, start1, i, s2, start2) && recurse(s1, start1 + i, len - i, s2, start2 + i)) ||
				(recurse(s1, start1, i, s2, start2 + len - i) && recurse(s1, start1 + i, len - i, s2, start2))
				){
				return true;
			}
		}

		return false;
	}
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		return recurse(s1, 0, s1.size(), s2, 0);
	}

	bool isScramble2(string s1, string s2){
		if (s1 == s2) return true;
		if (s1.size() != s2.size()) return false;
		vector<vector<vector<bool>>> dp(s1.size() + 1, vector<vector<bool>>(s1.size(), vector<bool>(s1.size(), false)));
		for (int i = 0; i < s1.size(); i++){
			for (int j = 0; j < s1.size(); j++){
				dp[1][i][j] = s1[i] == s2[j];
			}
		}

		for (int len = 2; len <= s1.size(); len++){
			for (int i = 0; i < s1.size() - len + 1; i++){
				for (int j = 0; j < s1.size() - len + 1; j++){
					for (int subLen = 1; subLen < len && !dp[len][i][j]; subLen++){
						dp[len][i][j] = (dp[subLen][i][j] && dp[len - subLen][i + subLen][j + subLen]) ||
							(dp[subLen][i][j + len - subLen] && dp[len - subLen][i + subLen][j]);
					}
				}
			}
		}
		return dp[s1.size()][0][0];
	}

	bool recurse2(string s1, int start1, int len, string s2, int start2, vector<vector<vector<int>>>& memo){
		if (memo[len][start1][start2] != -1) return  memo[len][start1][start2];

		if (len == 1){  
			memo[len][start1][start2] = s1[start1] == s2[start2] ? 1 : 0;
			return memo[len][start1][start2];
		} 

		for (int i = 1; i < len; i++){
			if ((recurse2(s1, start1, i, s2, start2, memo) && recurse2(s1, start1 + i, len - i, s2, start2 + i, memo)) ||
				(recurse2(s1, start1, i, s2, start2 + len - i, memo) && recurse2(s1, start1 + i, len - i, s2, start2, memo))
				){
				return memo[len][start1][start2] = 1;
			}
		}

		return memo[len][start1][start2] = 0;
	}

	bool isScramble3(string s1, string s2){
		if (s1 == s2) return true;
		if (s1.size() != s2.size()) return false;
		vector<vector<vector<int>>> memo(s1.size() + 1, vector<vector<int>>(s1.size(), vector<int>(s1.size(), -1)));
		return recurse2(s1, 0, s1.size(), s2, 0, memo);
	}
};

int main(void){
	string s1 = "great";
	string s2 = "rgeat";

	Solution model;
	//bool result = model.isScramble(s1, s2);
	//bool result = model.isScramble2(s1, s2);
	bool result = model.isScramble3(s1, s2);

	return 0;
}