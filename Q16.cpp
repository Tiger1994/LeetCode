#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		double min_dis = INFINITY;
		int lens = nums.size();

		sort(nums.begin(), nums.end());
		for (int i = 0; i < lens-2; i++){
			if (i >= 1 && nums[i] == nums[i - 1]) continue;
			int low = i + 1;
			int high = lens - 1;
			while (low < high){
				int temp = nums[i] + nums[low] + nums[high];

				if (temp == target) return target;
				else{
					if (abs(temp - target) < min_dis){
						result = temp;
						min_dis = abs(temp - target);
					} 
					if (temp > target){
						while (high>i + 2 && nums[high] == nums[high - 1]) high--;
						high--;
					}
					else{
						while (low<high && nums[low] == nums[low + 1]) low++;
						low++;
					}
				}
			}
		}

		return result;
	}
};

int main(void){
	vector<int> nums = { -3, -2, -5, 3, -4 };

	Solution model;
	int result = model.threeSumClosest(nums, -1);

	return 0;
}