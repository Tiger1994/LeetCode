#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool compare(int a, int b) {
		if (a == 0) return false;
		if (b == 0) return true;
		long long ap = a, bp = b;
		for (int i = a; i; i /= 10) bp *= 10;
		bp += a;
		for (int i = b; i; i /= 10) ap *= 10;
		ap += b;
		return ap > bp;
	}

	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), &compare);
		string res;
		for (auto i : nums) {
			string tmp = to_string(i);
			if (i == 0) {
				if (res.empty()) res += tmp;
				else if (res != "0") res += tmp;
				else continue;
			}
			else res += tmp;
		}
		return res;
	}
};

class Solution2 {
public:
	static bool com(string a, string b) {
		return (a + b) > (b + a);
	}
	string largestNumber(vector<int>& nums) {
		vector<string> ns;
		for (auto i : nums) { ns.push_back(to_string(i)); }
		sort(ns.begin(), ns.end(), &com);
		string res;
		for (auto s : ns) {
			res += s;
		}
		if (res[0] == '0') return "0";
		else return res;
	}
};

int main(void) {
	vector<int> nums = { 0,0, 1 };
	Solution mode;
	string res = mode.largestNumber(nums);
	return 0;
}