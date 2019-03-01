#include<vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) return 1;
		vector<bool> records(nums.size(), false);
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] <= 0 || nums[i]>nums.size()) continue;
			else records[nums[i] - 1] = true;
		}
		for (int i = 0; i<nums.size(); i++) {
			if (records[i]) continue;
			else return i + 1;
		}

		return nums.size() + 1;
	}

	int firstMissingPositive2(vector<int> &nums) {
		if (nums.size() == 0) return 1;
		for (decltype(nums.size()) i = 0; i < nums.size(); i++) {
			while (nums[i] <= nums.size() && nums[i] > 0 && (nums[i] != nums[nums[i]-1])) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (decltype(nums.size()) i = 0; i < nums.size(); i++) {
			if (nums[i]!=i+1) return int(i + 1);
		}
		return int(nums.size() + 1);
	}
};

int main(void) {
	vector<int> nums = { 1,1 };

	Solution model;
	int result = model.firstMissingPositive2(nums);

	return 0;
}
