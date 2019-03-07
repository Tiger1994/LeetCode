#include<string>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (auto i : s) {
			res = res * 26 + (i - 'A' + 1);
		}
		return res;
	}
};

int main(void) {
	string s = "AB";
	Solution mode;
	int res = mode.titleToNumber(s);
	return 0;
}