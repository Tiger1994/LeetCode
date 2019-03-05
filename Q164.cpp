#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		int res = INT_MIN;
		for (decltype(nums.size()) i = 1; i < nums.size(); i++) {
			res = max(res, abs(tmp[i] - tmp[i-1]));
		}
		return res;
	}

};

class Bucket {
public:
	bool used = false;
	int _min = INT_MAX;
	int _max = INT_MIN;
};

class Solution2 {
public:
	int maximumGap(vector<int> &nums) {
		if (nums.size() < 2) return 0;
		int mini = *min_element(nums.begin(), nums.end());
		int maxi = *max_element(nums.begin(), nums.end());
		int bSize = max(1, (maxi - mini) / int(nums.size() - 1));
		int bNum = (maxi - mini) / bSize + 1;
		vector<Bucket> buckets(bNum);
		for (auto num : nums) {
			int bIdx = (num - mini) / bSize;
			buckets[bIdx].used = true;
			buckets[bIdx]._min = min(num, buckets[bIdx]._min);
			buckets[bIdx]._max = max(num, buckets[bIdx]._max);
		}

		int preMax = mini, res = INT_MIN;
		for (auto bucket : buckets) {
			if (!bucket.used) continue;
			res = max(res, bucket._min - preMax);
			preMax = bucket._max;
		}
		return res;
	}
};

int main(void) {
	vector<int> nums = { 3,6,9,1 };
	Solution2 mode;
	int res = mode.maximumGap(nums);
	return 0;
}