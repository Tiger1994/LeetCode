#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> set;
		for (int num : nums){
			if (set.find(num) == set.end())
				set.insert(num);
			else set.erase(num);
		}

		return *set.begin();
	}

	int singleNumber2(vector<int>& nums){
		int res = 0;
		for (int num : nums)
			res ^= num;
		return res;
	}
};

int main(void){
	vector<int> nums = { 4, 1, 2, 1, 2 };

	Solution model;
	int res = model.singleNumber2(nums);

	return 0;
}