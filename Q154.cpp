#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int res = INT_MAX;
		for (auto i : nums) res = min(res, i);
		return res;
	}

	int findMin2(vector<int> &nums){
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return min(nums[0], nums[1]);

		decltype(nums.size()) left = 0;
		decltype(nums.size()) right = nums.size() - 1;
		decltype(nums.size()) mid = (left + right) / 2;
		while (right - left >= 2){
			while (right - left >= 2 && nums[left] == nums[right]) right--;
			if (right - left < 2) break;
			mid = (left + right) / 2;
			if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) return nums[mid];
			if (nums[mid] >= nums[left] && nums[left] >= nums[right]){
				left = mid;
				mid = (left + right) / 2;
			}
			else{
				right = mid;
				mid = (left + right) / 2;
			}
		}
		return min(nums[left], nums[right]);
	}
};

int main(void){
	vector<int> nums = { 3, 3, 3, 1 };

	Solution mode;
	int res = mode.findMin2(nums);
	return 0;
}