#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch_1(string s, string p) {
		int sLen = s.size(), pLen = p.size();
		if (sLen == 0 && pLen == 0) return true;
		vector<vector<bool>> dp(sLen+1, vector<bool>(pLen + 1, false));
		dp[sLen][pLen] = true;
		int i = sLen - 1, j = pLen - 1;
		for (int i = sLen; i >= 0;i--){
			for (int j = pLen - 1; j >= 0; j--){
				if (p[j] == '?'){
					dp[i][j] = i + 1 <= sLen && dp[i + 1][j + 1];
				}
				else if (p[j] == '*'){
					dp[i][j] = dp[i][j + 1] || (i + 1 <= sLen && dp[i + 1][j]);
				}
				else{
					dp[i][j] = s[i] == p[j] && i+1<=sLen && dp[i+1][j+1];
				}
			}
		}

		return dp[0][0];
	}

	bool isMatch_2(string s, string p){
		if (s.size() == 0 && p.size() == 0) return 0;
		int lastS = s.size(), lastP = p.size();
		int currS = 0, currP = 0;
		while (currS < s.size()){
			if (p[currP] == '*') lastP = currP, lastS = currS, currP++;
			else if (p[currP] == '?' || s[currS] == p[currP]) currP++, currS++;
			else if (lastS <= s.size()-1) currP = lastP, currS = ++lastS;
			else return false;
		}

		while (p[currP] == '*') currP++;
		return currP == p.size();
	}
};

int main(void){
	string s = "aa", p = "a";

	Solution model;
	//bool result = model.isMatch_1(s, p);
	bool result = model.isMatch_2(s, p);

	return 0;
}