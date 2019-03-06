#include<string>
#include<map>
#include<limits>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res1;
		bool dot = false;
		long long num = numerator;
		long long deno = denominator;
		num = abs(num);
		deno = abs(deno);

		if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) res1 += '-';
		int locate = 0;
		map<int, int> remainder;
		while(1) {
			long long quotient = num / deno;
			res1 += to_string(quotient);
			num = num % deno;
			if (!num) break;
			else {
				locate++;
				num *= 10;
				if (remainder.find(num) != remainder.end()) break;
				remainder[num] = locate;
				if (!dot) res1 += '.', dot = true;
			}
		}
		
		locate = remainder[num];
		if (num) {
			string res2;
			res1 += ')';
			bool meet_dot = false, need_a = true;
			int count = 0;
			for (auto i : res1) {
				if (count == locate && meet_dot && need_a) res2 = (res2 + "(")+i, need_a = false;
				else if (i == '.') meet_dot = true, res2 += i;
				else res2 += i;

				if (meet_dot) count++;
			}
			return res2;
		}
		else return res1;
	}
};

class Solution {
public:
	string fractionToDecimal(int64_t n, int64_t d) {
		// zero numerator
		if (n == 0) return "0";

		string res;
		// determine the sign
		if (n < 0 ^ d < 0) res += '-';

		// remove sign of operands
		n = abs(n), d = abs(d);

		// append integral part
		res += to_string(n / d);

		// in case no fractional part
		if (n % d == 0) return res;

		res += '.';

		map<int, int> map;

		// simulate the division process
		int64_t r = n % d;
		while (r) {

			// meet a known remainder
			// so we reach the end of the repeating part
			if (map.count(r) > 0) {
				res.insert(map[r], 1, '(');
				res += ')';
				break;
			}

			// the remainder is first seen
			// remember the current position for it
			map[r] = res.size();

			r *= 10;

			// append the quotient digit
			res += to_string(r / d);
			r %= d;
		}

		return res;
	}
};

int main(void) {
	int numerator = INT_MIN, denominator = 1;
	Solution mode;
	string res = mode.fractionToDecimal(numerator, denominator);
	return 0;
}