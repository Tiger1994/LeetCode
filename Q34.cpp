#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size()-1;
		while (left <= right){
			int idx = (left + right) / 2;
			if (nums[idx] == target){
				int left_idx = idx, right_idx = idx;
				while (left_idx >=0 && nums[left_idx] == target) left_idx--;
				while (right_idx <= right && nums[right_idx] == target) right_idx++;
				return{ left_idx + 1, right_idx - 1 };
			}
			if (nums[idx] > target){
				right = idx - 1;
			}
			else left = idx + 1;
		}

		return{ -1, -1 };
	}
};

int main(void){
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 6;

	Solution model;
	vector<int> result = model.searchRange(nums, target);

	return 0;
}