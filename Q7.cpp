#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
	int reverse_1(int x) {
		if (x == 0) return 0;
		int symbol = 1;
		if (x < 0){
			symbol = -1;
			x = abs(x);
		}

		vector<int> digits;
		while (x){
			digits.push_back(x % 10);
			x /= 10;
		}

		double result = 0;
		for (int i = 0; i < digits.size();i ++){
			result += digits[i] * pow(10, digits.size()-i-1);
		}

		if (result > INT_MAX || result < INT_MIN){
			return 0;
		}
		return int(symbol*result);
	}

	int reverse(int x) {
		double result = 0;
		while (x){
			if (result*10 < INT_MIN || result*10 > INT_MAX) return 0;
			result = 10 * result + x % 10;
			x /= 10;
		}

		return int(result);
	}
};

int main(void){
	Solution model;

	int result = model.reverse(123);

	return 0;
}