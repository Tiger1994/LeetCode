#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size()-1;

		while (left <= right){
			int idx = (left + right) / 2;
			if (nums[idx] == target) return idx;
			if (nums[idx] >= nums[0] && target < nums[0]) left = idx+1;
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

		return -1;
	}
};

int main(void){
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 0;

	Solution model;
	int result = model.search(nums, target);

	return 0;
}