#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (!nums.size()) return 0;
		int count = 1, len = 0;
		for (int i = 1; i < nums.size(); i++){
			if (nums[len] == nums[i]){
				count++;
				if (count == 2) nums[++len] = nums[i];
			}
			else{
				count = 1;
				nums[++len] = nums[i];
			}
		}
		return len + 1;
	}
};

int main(void){
	vector<int> nums = { 1, 1, 1, 2, 2, 3 };

	Solution model;
	int result = model.removeDuplicates(nums);

	return 0;
}