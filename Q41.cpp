#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		if(nums.size() == 0) return 1;
        vector<bool> records(nums.size(), false);
		for(int i = 0;i<nums.size();i++){
			if(nums[i]<=0 || nums[i]>nums.size()) continue;
			else records[nums[i]-1] = true;
		}
		for(int i = 0;i<nums.size();i++){
			if(records[i]) continue;
			else return i+1;
		}

		return nums.size()+1;
    }
};

int main(void){
	vector<int> nums = {7,8,9,11,12};

	Solution model;
	int result = model.firstMissingPositive(nums);

	return 0;
}