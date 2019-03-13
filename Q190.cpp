#include<cstdint>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		int count = 31;
		while (count >= 0) {
			if (n % 2) {res = res << 1; res += 1;}
			else res = res << 1 + 0;
			n = n>>1;
			count--;
		}
		return res;
	}

	uint32_t reverseBits2(uint32_t n) {
		uint32_t res = 0;
		int count = 31;
		while (count >= 0) {
			res = res << 1;
			res = res | (n & 1);
			n = n >> 1;
			count--;
		}
		return res;
	}
};

int main(void) {
	uint32_t n = 43261596;
	Solution mode;
	uint32_t res = mode.reverseBits2(n);
	return 0;
}