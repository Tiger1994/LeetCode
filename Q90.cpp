#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void recurse(vector<int> nums, vector<int> next, vector<vector<int>> &result){
		result.push_back(next);
		for (int i = 0; i < nums.size(); i++){
			if (i>0 && nums[i - 1] == nums[i]) continue;
			vector<int> temp = nums; vector<int> tempNext = next;
			temp.erase(temp.begin(), temp.begin() + i+1); tempNext.push_back(nums[i]);
			recurse(temp, tempNext, result);
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		recurse(nums, {}, result);
		return result;
	}
};

int main(void){
	vector<int> nums = { 1, 2, 2 };

	Solution model;
	vector<vector<int>> result = model.subsetsWithDup(nums);

	return 0;
}