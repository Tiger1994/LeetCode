#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		
		bool flag = true;
		int first_idx = 0;
		for (int i = nums.size() - 1; i > 0; i--){
			if (nums[i] > nums[i - 1]){
				first_idx = i - 1;  flag = false; break;
			} 
		}
		
		if (flag){
			sort(nums.begin(), nums.end());
			return;
		}

		int change_idx = first_idx;
		int temp_max = INT_MAX;
		for (int i = first_idx + 1; i < nums.size(); i++){
			if (nums[first_idx] < nums[i] && nums[i] < temp_max)
				change_idx = i; temp_max = nums[i];
		}

		int temp = nums[first_idx];
		nums[first_idx] = nums[change_idx]; nums[change_idx] = temp;

		sort(nums.begin() + first_idx+1, nums.end());
	}
};

int main(void){
	vector<int> nums = { 1, 2, 3 };

	Solution model;
	model.nextPermutation(nums);

	return 0;
}