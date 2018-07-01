#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = INT_MIN, result = INT_MIN;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i]>maxSum)	maxSum = nums[i];
			else maxSum += nums[i];
			result = max(result, maxSum);
		}

		return result;
	}
};

int main(void){
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	Solution model;
	int result = model.maxSubArray(nums);

	return 0;
}