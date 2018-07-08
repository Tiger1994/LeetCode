#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		if (!word1.size() || !word2.size()) return word1.size() ? word1.size() : word2.size();
		vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
		dp[0][0] = word1[0] == word2[0] ? 0 : 1;
		for (int i = 0; i <= word1.size(); i++)
			dp[i][0] = i;
		for (int i = 1; i <= word2.size(); i++)
			dp[0][i] = i;

		for (int i = 1; i <= word1.size(); i++){
			for (int j = 1; j <= word2.size(); j++){
				if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i - 1][j - 1];
				else{
					vector<int> choices = { dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] };
					dp[i][j] = 1 + *min_element(choices.begin(), choices.end());
				}
			}
		}

		return dp[word1.size() - 1][word2.size() - 1];
	}
};

int main(void){
	string word1 = "abc";
	string word2 = "ac";

	Solution model;
	int result = model.minDistance("horse", "ros");

	return 0;
}