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

	int climbStairs2(int n){
		int f = 0, g = 1;
		while (n--) {
			g += f; f = g - f;
		}

		return g;
	}
};

int main(void){
	int n = 1;

	Solution model;
	int result = model.climbStairs2(n);

	return 0;
}