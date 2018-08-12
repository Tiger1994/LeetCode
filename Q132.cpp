#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s){
		int left = 0, right = s.size() - 1;
		while (left <= right){
			if (s[left] != s[right]) return false;
			left++; right--;
		}

		return true;
	}

	void helper(string s, int count, int &res){
		if (s.empty()){
			res = min(res, count);
			return;
		}

		string prefix;
		while (!s.empty()){
			prefix += s.substr(0, 1);
			s.erase(0, 1);
			if (isPalindrome(prefix)){
				helper(s, count+1, res);
			}
		}
	}

	int minCut(string s) {
		int res = INT_MAX;
		helper(s, 0, res);
		return res-1;
	}

	int minCut2(string s) {
		vector<int> dp(s.size(), 0);
		vector<vector<bool>> mp(s.size(),vector<bool>(s.size(), false));

		for (int i = s.size()-1; i >= 0; i--){
			for (int j = i; j < s.size(); j++){
				if (s[i] == s[j] && (j - i < 2 || mp[i + 1][j - 1]))
					mp[i][j] = true;
			}
		}

		for (int i = 1; i < s.size(); i++){
			if (mp[0][i]){
				dp[i] = 0;
				continue;
			}
			int res = s.size();
			for (int j = 0; j < i; j++){
				if (mp[j+1][i] && res > dp[j] + 1)
					res = dp[j] + 1;
			}
			dp[i] = res;
		}

		return dp[s.size() - 1];
	}
};

int main(void){
	string s = "aaabaa";

	Solution model;
	int res = model.minCut2(s);

	return 0;
}