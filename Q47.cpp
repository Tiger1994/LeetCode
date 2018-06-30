#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void recurse(vector<int> nums, vector<int> permutation, vector<vector<int>>& permutations){
		if (nums.size() == 0) {
			permutations.push_back(permutation);
			return;
		}

		else{
			for (int i = 0; i < nums.size(); i++){
				if (i>0 && nums[i] == nums[i - 1]) continue;
				vector<int> tNums = nums;
				permutation.push_back(tNums[i]);
				tNums.erase(tNums.begin() + i);
				recurse(tNums, permutation, permutations);
				permutation.pop_back();
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> permutations;
		sort(nums.begin(), nums.end());
		recurse(nums, {}, permutations);
		return permutations;
	}

	vector<vector<int>> permuteUnique_2(vector<int>& nums){
		vector<vector<int>> permutations;
		//if (nums.size() < 2) return { nums };
		permutations.push_back(nums);
		int position = 0;
		for (int i = 0; i < nums.size() - 1; i++){
			int pSize = permutations.size();
			for (int j = 0; j < pSize; j++){
				sort(permutations[j].begin()+position, permutations[j].end());
				for (int k = position + 1; k < nums.size(); k++){
					vector<int> tempP = permutations[j];
					if (k > 0 && tempP[k - 1] == tempP[k]) continue;
					int t = tempP[position]; tempP[position] = tempP[k]; tempP[k] = t;
					permutations.push_back(tempP);
				}
			}
			position++;
		}

		return permutations;
	}
};

int main(void){
	vector<int> nums = { 3, 3, 0, 3 };

	Solution model;
	//vector<vector<int>> permutations = model.permuteUnique(nums);
	vector<vector<int>> permutations = model.permuteUnique_2(nums);

	return 0;
}