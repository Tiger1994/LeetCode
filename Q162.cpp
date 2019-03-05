#include<vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		if (nums[0] > nums[1]) return 0;
		if (nums[nums.size() - 2] < nums[nums.size()-1]) return nums.size() - 1;
		for (decltype(nums.size()) i = 1; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) return i;
		}
		return -1;
	}

	int findPeakElement2(vector<int>& nums) {
		decltype(nums.size()) head = 0, tail = nums.size() - 1, mid;
		while (head < tail) {
			mid = (head + tail) / 2;
			if (nums[mid] < nums[mid + 1]) head = mid+1;
			else tail = mid;
		}
		return head;
	}
};

int main(void) {
	vector<int> nums = {1,2,3};

	Solution mode;
	int res = mode.findPeakElement(nums);

	return 0;
}