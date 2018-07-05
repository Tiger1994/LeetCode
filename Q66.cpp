#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		int carryBit = 0; digits[len - 1] += 1;
		for (int i = len - 1; i >= 0; i--){
			int tempSum = digits[i] + carryBit;
			digits[i] = tempSum % 10;
			carryBit = tempSum / 10;
		}
		if (carryBit) digits.insert(digits.begin(), carryBit);
		return digits;
	}
};

int main(void){
	vector<int> digits = { 1, 2, 3 };

	Solution model;
	vector<int> result = model.plusOne(digits);

	return 0;
}