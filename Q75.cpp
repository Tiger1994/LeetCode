#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = -1, right = nums.size();
		int idx = 0;
		while (idx < right){
			if (nums[idx] == 0) swap(nums[++left], nums[idx]);
			if (nums[idx] == 2) swap(nums[--right], nums[idx]);
			else idx++;
		}
	}
};

int main(void){
	vector<int> nums = { 1, 2, 0 };

	Solution model;
	model.sortColors(nums);

	return 0;
}