#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int steps = 0, oldIdx = 0;
		int nextJump = oldIdx + nums[oldIdx];
		if (nextJump >= nums.size() - 1) return steps + 1;

		while(oldIdx < nums.size()){
			int maxJump = 0, newIdx = oldIdx;
			for (int j = oldIdx; j <= oldIdx + nums[oldIdx]; j++){
				int nextJump = j + nums[j];
				if (nextJump >= nums.size() - 1) return steps+2;
				if (j + nums[j] > maxJump){
					maxJump = j + nums[j];
					newIdx = j;
				}
			}

			oldIdx = newIdx;
			steps++;
		}
	}
};

int main(void){
	vector<int> nums = { 7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3 };

	Solution model;
	int result = model.jump(nums);

	return 0;
}