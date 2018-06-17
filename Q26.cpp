#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates_1(vector<int>& nums) {
		if (!nums.size()) return 0;
		int len = 0, loc = 0;
		for (int i = 0; i < nums.size() - 1; i++){
			if (nums[i] == nums[i + 1]) continue;
			nums[len] = nums[loc];
			len++; loc = i + 1;
		}
		nums[len] = nums[loc];
		return len + 1;
	}

	int removeDuplicates_2(vector<int>& nums) {
		if (!nums.size()) return 0;
		int len = 0;
		for (int i = 0; i < nums.size() - 1; i++){
			if (nums[len] == nums[i]) continue;
			else nums[++len] = nums[i];
		}
		return len + 1;
	}
};

int main(void){
	vector<int> nums = { 1, 1, 2};

	Solution model;
	int result = model.removeDuplicates_2(nums);

	return 0;
}