#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums, int target){
		vector<vector<int>> result;
		int lens = nums.size();
		if (lens < 3) return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < lens - 2; i++){
			// skip the duplication
			if (i >= 1 && nums[i - 1] == nums[i]) continue;

			int low = i + 1;
			int high = lens - 1;
			while (low < high){
				int a = nums[i];
				int b = nums[low];
				int c = nums[high];
				if (a + b + c == target){
					vector<int> temp;
					temp.push_back(a);
					temp.push_back(b);
					temp.push_back(c);
					result.push_back(temp);
					while (low < lens - 1 && nums[low] == nums[low + 1]) low++;
					while (high > i && nums[high - 1] == nums[high]) high--;
					low++;
					high--;
				}
				else if (a + b + c > target){
					while (high > i && nums[high - 1] == nums[high]) high--;
					high--;
				}
				else{
					while (low < lens - 1 && nums[low] == nums[low + 1]) low++;
					low++;
				}
			}
		}

		return result;
	}


	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;

		int lens = nums.size();
		if (lens < 4) return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < lens - 3; i++){
			if (i>2 && nums[i] == nums[i - 1]) continue;
			vector<int> nums_temp(nums.begin() + i + 1, nums.end());
			vector<vector<int>> temp_result = this->threeSum(nums_temp, target - nums[i]);
			for (int j = 0; j < temp_result.size(); j++){
				temp_result[j].insert(temp_result[j].begin(), nums[i]);
				result.push_back(temp_result[j]);
			}
		}

		return result;
	}
};

int main(void){
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;

	Solution model;
	vector<vector<int>> result = model.fourSum(nums, target);

	return 0;
}