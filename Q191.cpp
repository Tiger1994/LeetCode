#include<cstdint>
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count(0);
		while (n) {
			count += (n & 1);
			n = n >> 1;
		}
		return count;
	}
};
int main(void) {
	uint32_t n = 3;
	Solution mode;
	int res = mode.hammingWeight(n);
	return 0;
}