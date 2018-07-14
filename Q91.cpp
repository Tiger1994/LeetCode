#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0) return 0;
		vector<int> dp(s.size(), 0);
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '0'){
				bool situation1 = i>=2 && s[i - 1] > '0' && s[i-1] <= '2';
				bool situation2 = i == 1 && s[i - 1] > '0' && s[i - 1] <= '2';
				if (situation1) dp[i] = dp[i - 2];
				else if (situation2) dp[i] = dp[i - 1];
				else dp[i] = 0;
			}
			else{
				if (i > 1){
					bool situation1 = s[i - 1] == '1';
					bool situation2 = s[i - 1] == '2' && s[i] <= '6';
					if (situation1 || situation2) dp[i] = dp[i - 1] + dp[i - 2];
					else dp[i] = dp[i - 1];
				}
				else if (i == 1){
					bool situation1 = s[i - 1] == '1';
					bool situation2 = s[i - 1] == '2' && s[i] <= '6';
					if (situation1 || situation2) dp[i] = dp[i - 1] + 1;
					else dp[i] = dp[i - 1];
				}
				else{
					dp[i] = 1;
				}
			}
		}

		return dp[s.size() - 1];
	}
};

int main(void){
	string s = "227";

	Solution model;
	int result = model.numDecodings(s);

	return 0;
}