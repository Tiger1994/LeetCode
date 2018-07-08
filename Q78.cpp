#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void enumerate(vector<int> nums, vector<int> solution, vector<vector<int>> &result){
		result.push_back(solution);
		for (int i = 0; i < nums.size(); i++){
			vector<int> newNums = nums;
			vector<int> newSolution = solution;
			newNums.erase(newNums.begin(), newNums.begin() + i + 1);
			newSolution.push_back(nums[i]);
			enumerate(newNums, newSolution, result);
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0) return{};
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		enumerate(nums, {}, result);
		return result;
	}
};

int main(void){
	vector<int> nums = { 1, 2, 3 };

	Solution model;
	vector<vector<int>> result = model.subsets(nums);

	return 0;
}