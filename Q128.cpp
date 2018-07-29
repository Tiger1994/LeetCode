#include<vector>
#include<map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int, int> records;
		for (int num : nums) records[num] = 1;

		int res = 0;
		for (auto iter = records.begin(); iter != records.end(); iter++){
			if (iter->second == 0) continue;
			int count = 1;
			for (int temp = iter->first + 1; records[temp] == 1; temp++){
				records[temp] = 0;
				count++;
			}
			for (int temp = iter->first - 1; records[temp] == 1; temp--){
				records[temp] = 0;
				count++;
			}
			res = max(res, count);
		}

		return res;
	}

	int longestConsecutive2(vector<int>& nums){
		unordered_set<int> records;
		for (int num : nums) records.insert(num);
		int res;
		while (records.size()){
			int it = *records.begin();
			int count = 1;
			records.erase(it);
			for (int temp = it + 1; records.find(temp) != records.end(); temp++){
				records.erase(temp);
				count++;
			}
			for (int temp = it - 1; records.find(temp) != records.end(); temp--){
				records.erase(temp);
				count++;
			}
			res = max(res, count);
		}

		return res;
	}
};

int main(void){
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };

	Solution model;
	int res = model.longestConsecutive2(nums);

	return 0;
}