#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		vector<int> single(32, 0);
		for (int i = 0; i < 32; i++){
			for (int j = 0; j < nums.size(); j++){
				if (nums[j] >> i & 1) single[i]++;
			}
			single[i] %= 3;
			res |= single[i] << i;
		}

		return res;
	}

	int singleNumber2(vector<int>& nums){
		int ones = 0, twice = 0, thirds = 0;
		for (int i = 0; i < nums.size(); i++){
			twice |= ones & nums[i];
			ones ^= nums[i];
			thirds = ones & twice;
			ones &= ~(ones&thirds);
			twice &= ~(twice&thirds);
		}

		return ones;
	}
};

int main(void){
	vector<int> nums = { 2, 2, 3, 2 };

	Solution model;
	int res = model.singleNumber2(nums);

	return 0;
}