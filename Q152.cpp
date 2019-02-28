#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN;
		for (decltype(nums.size()) i = 0; i < nums.size(); i++) {
			int tmp = nums[i];
			res = max(res, tmp);
			for (decltype(nums.size()) j = i + 1; j < nums.size(); j++) {
				tmp *= nums[j];
				res = max(res, tmp);
			}
		}
		return res;
	}

	int maxProduct2(vector<int> &nums) {
		if (nums.size() == 1) return nums[0];
		int res = nums[0];
		int max_p = nums[0];
		int min_n = nums[0];
		for (auto it = nums.begin() + 1; it != nums.end();it++) {
			int tmp = max_p;
			max_p = max(max(min_n*(*it), tmp*(*it)), *it);
			min_n = min(min(min_n*(*it), tmp*(*it)), *it);
			res = max(res, max_p);
		}
		return res;
	}
};

int main(void) {
	vector<int> nums = { 2,3,-2,4 };

	Solution mode;
	int res = mode.maxProduct2(nums);

	return 0;
}
