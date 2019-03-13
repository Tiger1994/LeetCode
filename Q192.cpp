#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int m = int(nums.size());
		if (m == 0) return 0;
		if (m == 1) return nums[0];
		if (m == 2) return max(nums[0], nums[1]);
		vector<int> dp(m, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < m; i++) {
			dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
		}
		return dp[m-1];
	}
};

int main(void) {
	vector<int> nums = { 2,7,9,3};
	Solution mode;
	int res = mode.rob(nums);
	return 0;
}