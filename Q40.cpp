#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	void recurse(vector<int> candidates, int target, vector<int> curr, int currIdx){
		int sum = accumulate(curr.begin(), curr.end(), 0);
		if (sum == target){
			result.push_back(curr); return;
		}
		else if (sum > target) return;

		for (int i = currIdx+1; i < candidates.size(); i++){
			if (i > currIdx + 1 && candidates[i] == candidates[i - 1]) continue;
			curr.push_back(candidates[i]);
			recurse(candidates, target, curr, i);
			curr.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> curr;
		sort(candidates.begin(), candidates.end());

		recurse(candidates, target, curr, -1);
		return result;
	}
};

int main(void){
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;

	Solution model;
	vector<vector<int>> result = model.combinationSum2(candidates, target);

	return 0;
}