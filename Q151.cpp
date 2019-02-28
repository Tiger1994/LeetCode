#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		vector<string> tmp;
		string word;
		s += ' ';
		for (auto i : s) {
			if (isspace(i)) {
				if (!word.empty()) tmp.push_back(word);
				word = "";
			}
			else {
				word += i;
			}
		}

		if (tmp.empty()) return word;
		string res;
		for (auto it = tmp.end() - 1; it != tmp.begin(); it--) {
			res += *it + ' ';
		}
		res += tmp.front();
		return res;
	}
};

int main(void) {
	string s = "a good   example";
	Solution mode;
	string res = mode.reverseWords(s);
	return 0;
}