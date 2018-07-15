#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() == 0) return s2 == s3;
		if (s2.size() == 0) return s1 == s3;
		vector<vector<vector<bool>>> dp(s1.size() + 1, vector<vector<bool>>(s2.size() + 1, vector<bool>(s3.size() + 1, false)));
		dp[0][0][0] = true;
		for (int i = 1; i <= s1.size(); i++){
			if (s1[i - 1] == s3[i - 1]) dp[i][0][i] = dp[i-1][0][i-1];
		}
		for (int i = 1; i <= s2.size(); i++){
			if (s2[i - 1] == s3[i - 1]) dp[0][i][i] = dp[0][i-1][i-1];
		}
		for (int i = 1; i <= s1.size(); i++){
			for (int j = 1; j <= s2.size(); j++){
				int k = i + j;
				if (s1[i - 1] == s3[k - 1]) dp[i][j][k] = dp[i - 1][j][k - 1];
				if (s2[j - 1] == s3[k - 1]) dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][k - 1];
			}
		}

		return dp[s1.size()][s2.size()][s3.size()];
	}

	bool isInterleave2(string s1, string s2, string s3) {
		if (s1.size() == 0) return s2 == s3;
		if (s2.size() == 0) return s1 == s3;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= s1.size(); i++){
			if (s1[i - 1] == s3[i - 1]) dp[i][0] = dp[i - 1][0];
		}
		for (int i = 1; i <= s2.size(); i++){
			if (s2[i - 1] == s3[i - 1]) dp[0][i] = dp[0][i - 1];
		}
		for (int i = 1; i <= s1.size(); i++){
			for (int j = 1; j <= s2.size(); j++){
				int k = i + j;
				if (s1[i - 1] == s3[k - 1]) dp[i][j] = dp[i - 1][j];
				if (s2[j - 1] == s3[k - 1]) dp[i][j] = dp[i][j] || dp[i][j - 1];
			}
		}

		return dp[s1.size()][s2.size()] && (s1.size()+s2.size()) == s3.size();
	}
};

int main(void){
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";

	Solution model;
	bool result = model.isInterleave2(s1, s2, s3);

	return 0;
}