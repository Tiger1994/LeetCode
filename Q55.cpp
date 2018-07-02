#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int pos = 0;
		while (1){
			int maxJump = 0, newPos = pos;
			for (int i = pos; i <= pos+nums[pos]; i++){
				if (maxJump < i + nums[i]){
					maxJump = i + nums[i]; newPos = i;
				}
				if (maxJump >= nums.size()-1) return true;
			}
			if (pos == newPos) return false;
			else pos = newPos;
		}
	}
};

int main(void){
	vector<int> nums = { 2, 3, 1, 1, 4 };
	vector<int> nums2 = { 3, 2, 1, 0, 4 };
	vector<int> nums3 = { 1, 1, 2, 2, 0, 1, 1 };
	vector<int> nums4 = { 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0 };
	vector<int> nums5 = { 1, 2, 3 };

	Solution model;
	bool result = model.canJump(nums5);

	return 0;
}