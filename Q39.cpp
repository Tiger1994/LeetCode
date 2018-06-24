#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;

	void recurse(vector<int> candidates, int target, vector<int> curr){
		int sum = accumulate(curr.begin(), curr.end(), 0);
		if (sum == target){
			result.push_back(curr); return;
		}
		else if (sum > target) return;

		for (int i = 0; i < candidates.size(); i++){
			if(curr.size() >= 1 && curr.back() > candidates[i]) continue;
			else{
				curr.push_back(candidates[i]);
				recurse(candidates, target, curr);
				curr.pop_back();
			}
		}

		return;
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> curr;
		recurse(candidates, target, curr);

		return result;
	}
};

int main(void){
	vector<int> candidates = { 2, 3, 5};
	int target = 8;

	Solution model;
	vector<vector<int>> result = model.combinationSum(candidates, target);

	return 0;
}