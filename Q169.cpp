#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> m;
		for (auto i : nums) {
			m[i]++;
			if (m[i] * 2 > nums.size()) return i;
		}
		return -1;
	}
	int majorityElement2(vector<int>& nums) {
		int candidate = nums[0], count = 1;
		for (decltype(nums.size()) i = 1; i < nums.size(); i++) {
			if (nums[i] == candidate) count++;
			else {
				count--;
				if (count == 0) candidate = nums[i], count = 1;
			}
		}
		return candidate;
	}
};

int main(void) {
	vector<int> nums = { 2,2,1,1,1,2,2 };
	Solution mode;
	int res = mode.majorityElement(nums);
	return 0;
}