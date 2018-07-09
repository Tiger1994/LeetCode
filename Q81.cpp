#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		while (nums[0] == nums[nums.size() - 1] && nums.size() > 1) 
			nums.erase(nums.begin());
		int left = 0, right = nums.size() - 1;

		while (left <= right){
			int idx = (left + right) / 2;
			if (nums[idx] == target) return true;
			if (nums[idx] >= nums[0] && target < nums[0]) left = idx + 1;
			else if (nums[idx] >= nums[0] && target >= nums[0]){
				if (nums[idx] > target) right = idx - 1;
				else left = idx + 1;
			}
			else if (nums[idx] < nums[0] && target < nums[0]){
				if (nums[idx] > target) right = idx - 1;
				else left = idx + 1;
			}
			else right = idx - 1;
		}

		return false;
	}
};

int main(void){
	vector<int> nums = { 0, 0, 0 };

	Solution model;
	bool result = model.search(nums, 3);

	return 0;
}