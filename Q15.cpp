#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum_1(vector<int>& nums) {
		vector<vector<int>> result;
		int lens = nums.size();
		if (lens < 3) return result;
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < lens-2; i++){
			for (int j = i + 1; j < lens-1; j++){
				for (int k = j + 1; k < lens; k++){
					if (nums[i] + nums[j] + nums[k] == 0){
						vector<int> temp;
						bool flag = true;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						for (int m = 0; m < result.size(); m++){
							if (temp[0] == result[m][0] && temp[1] == result[m][1] && temp[2] == result[m][2]){
								flag = false;
								break;
							}
						}

						if (flag) result.push_back(temp);
					}
				}
			}
		}

		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> result;
		int lens = nums.size();
		if (lens < 3) return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < lens - 2; i++){
			// skip the duplication
			if (i >= 1 && nums[i-1] == nums[i]) continue;

			int low = i + 1;
			int high = lens - 1;
			while (low < high){
				int a = nums[i];
				int b = nums[low];
				int c = nums[high];
				if (a + b + c == 0){
					vector<int> temp;
					temp.push_back(a);
					temp.push_back(b);
					temp.push_back(c);
					result.push_back(temp);
					while (low < lens - 1 && nums[low] == nums[low + 1]) low++;
					while (high > i && nums[high-1] == nums[high]) high--;
					low++;
					high--;
				}
				else if (a + b + c > 0){
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
};

int main(void){
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	Solution model;

	vector<vector<int>> result = model.threeSum(nums);
	
	return 0;
}