#include<algorithm>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		return int(sqrt(x));
	}
	int mySqrt2(int x){
		if (x <= 0) return 0;
		double last = 0, rest = 1;
		while (last != rest){
			last = rest; rest = (rest + x / rest) / 2;
		}

		return int(last);
	}
	int mySqrt3(int x){
		if (x <= 0) return 0;
		int left = 0, right = (x+1)/2;
		while (left < right){
			long long mid = (left + right + 1) / 2;
			long long sq = mid*mid;
			if (sq == x) return int(mid);
			else if (sq < x) left = mid;
			else right = mid - 1;
		}

		return left;
	}
};

int main(void){
	int x = 8;

	Solution model;
	int reuslt = model.mySqrt3(2147483647);

	return 0;
}