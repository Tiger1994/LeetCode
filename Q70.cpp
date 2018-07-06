#include<vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;
		vector<int> dp(n, 1); dp[1] = 2;
		for (int i = 2; i < n; i++){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n - 1];
	}
};

int main(void){
	int n = 3;

	Solution model;
	int result = model.climbStairs(n);

	return 0;
}