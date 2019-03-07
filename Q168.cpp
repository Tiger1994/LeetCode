#include<string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string res;
		while (n > 0) {
			int mod = n % 26;
			if (mod) {
				res = char('A' + mod - 1) + res;
				n /= 26;
			}
			else {
				res = 'Z' + res;
				n = n / 26 - 1;
			}
		}
		return res;
	}
};

int main(void) {
	int n = 703;
	Solution mode;
	string res = mode.convertToTitle(n);
	return 0;
}