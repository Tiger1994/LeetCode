#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right){
			int mid = (left + right+1) / 2;
			if (nums[mid] == target) return mid;
			if (left == right) return mid + 1;
			if (nums[mid] > target) right = mid - 1;
			else left = mid;
		}
	}
};

int main(void){
	vector<int> nums = { 1, 3, 5, 6 };
	int target = 2;

	Solution model;
	int result = model.searchInsert(nums, target);

	return 0;
}