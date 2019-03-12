#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%int(nums.size());
		if (k == 0) return;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

int main(void) {
	vector<int> nums = { 1,2,3,4,5,6,7 };
	int k = 3;
	Solution mode;
	mode.rotate(nums, k);
	return 0;
}