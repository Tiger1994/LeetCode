#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (decltype(numbers.size()) i = 0; i < numbers.size(); i++) {
			for (decltype(numbers.size()) j = i + 1; j < numbers.size(); j++) {
				if (numbers[i] + numbers[j] == target) return{ int(i + 1), int(j + 1) };
			}
		}
		return{ 0, 0 };  // 结尾没有return是无法通过的
	}
	vector<int> twoSum2(vector<int> &numbers, int target) {
		int left = 0, right = int(numbers.size()) - 1;
		while (left < right) {
			if (numbers[left] + numbers[right] == target) return{ left + 1, right + 1 };
			else if (numbers[left] + numbers[right] > target) {
				if (numbers[left] + numbers[right - 1] > target) { right--; continue; }
				else if (numbers[left] + numbers[right - 1] < target) { left++; continue; }
				else return{ left + 1, right };
			}
			else {
				if (numbers[left + 1] + numbers[right] > target) { right--; continue; }
				else if (numbers[left + 1] + numbers[right] < target) { left++; continue; }
				else return{ left + 2, right + 1 };
			}
		}
		return{ 0, 0 };
	}

	vector<int> twoSum3(vector<int> &numbers, int target) {
		int left = 0, right = int(numbers.size())-1;
		while (left < right) {
			if (numbers[left] + numbers[right] == target) return{ left + 1, right + 1 };
			else if (numbers[left] + numbers[right] > target) right--;
			else left++;
		}
		return{ 0, 0 };
	}
};

int main(void) {
	vector<int> num = { 2,7,11,15 };
	int target = 9;
	Solution mode;
	vector<int> res = mode.twoSum3(num, target);
	return 0;
}