#include<vector>
using namespace std;

class Solution {
public:
	int removeElement_1(vector<int>& nums, int val) {
		if (!nums.size()) return 0;
		int len = 0;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] == val) continue;
			else nums[len++] = nums[i];
		}

		return len;
	}

	int removeElement_2(vector<int>& nums, int val){
		if (!nums.size()) return 0;
		int start = 0, end = nums.size()-1;
		while (start <= end){
			if (nums[start] == val)	nums[start] = nums[end--];
			else start++;
		}

		return end + 1;
	}
};

int main(void){
	vector<int> nums = { 0, 1, 0, 0, 3, 0, 4, 2 };
	int val = 2;

	Solution model;
	//int result = model.removeElement_1(nums, val);
	int result = model.removeElement_2(nums, val);

	return 0;
}