#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		set<string> res, duplicate;
		for (int i = 0; i + 9 < int(s.size()); i++) {
			string tmp(s.begin() + i, s.begin() + i + 10);
			if (duplicate.count(tmp)) res.insert(tmp);
			else duplicate.insert(tmp);
		}
		return vector<string>(res.begin(), res.end());
	}
};

int main(void) {
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution mode;
	vector<string> res = mode.findRepeatedDnaSequences(s);
	return 0;
}