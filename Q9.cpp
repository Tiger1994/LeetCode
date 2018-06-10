class Solution {
public:
	bool isPalindrome_1(int x) {
		if (x < 0) return false;

		double reverse = 0;  // ±ÜÃâÒç³ö£¬Ê¹ÓÃdouble
		int temp_x = x;
		while (temp_x){
			reverse = reverse * 10 + temp_x % 10;
			temp_x /= 10;
		}

		if (x == int(reverse)) return true;
		else return false;
	}

	bool isPalindrome(int x){
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int half_x = 0;
		while (x > half_x){
			half_x = half_x * 10 + x % 10;
			x /= 10;
		}

		return x == half_x || x == half_x/10;
	}
};

int main(void){
	int input = 1;

	Solution model;
	bool result = model.isPalindrome(input);

	return 0;
}