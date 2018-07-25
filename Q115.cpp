#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void helper(string s, string t, int &result){
		if (s.size() < t.size()) return;
		if (t.size() == 0) {
			result++;
			return;
		}
		if (s[0] == t[0]){
			string tempS = s;
			string tempT = t;
			tempS.erase(0, 1); tempT.erase(0, 1);
			helper(tempS, tempT, result);
			helper(tempS, t, result);
		}
		else{
			string tempS = s;
			tempS.erase(0, 1);
			helper(tempS, t, result);
		}
	}
	int numDistinct(string s, string t) {
		int result = 0;
		helper(s, t, result);
		return result;
	}

	int numDistinct2(string s, string t) {
		vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
		for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
		for (int i = 1; i <= t.size(); i++){
			if (s[i - 1] == t[i - 1]) dp[i][i] = dp[i - 1][i - 1];
			for (int j = i + 1; j <= s.size(); j++){
				if (s[j - 1] == t[i - 1])
					dp[j][i] = dp[j - 1][i - 1] + dp[j - 1][i];
				else
					dp[j][i] = dp[j - 1][i];
			}
		}

		return dp[s.size()][t.size()];
	}

	int numDistinct3(string s, string t){
		vector<int> dp(s.size() + 1, 1);
		for (int j = 0; j < t.size(); j++){
			int pre = dp[j];
			dp[j] = 0;
			for (int i = j + 1; i <= s.size(); i++){
				int temp = dp[i];
				dp[i] = s[i - 1] == t[j] ? dp[i - 1] + pre : dp[i - 1];
				pre = temp;
			}
		}

		return dp.back();
	}
};

int main(void){
	string s = "abbc";
	string t = "abc";

	Solution model;
	int result = model.numDistinct3(s, t);

	return 0;
}