#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> hash;
		int left = 0, len = INT_MAX, num = t.size(), start = 0;
		for (auto val : t) hash[val]++;
		for (int i = 0; i < s.size();i++){
			if (hash[s[i]]-- > 0) num--;
			while (num == 0){
				len = len < (i - left + 1) ? len : i - (start = left) + 1;
				if (hash[s[left++]]++ == 0) num++;
			}
		}

		return len == INT_MAX ? "" : s.substr(start, len);
	}
};


int main(void){
	string s = "ABCA";
	string t = "ABC";

	Solution model;
	string result = model.minWindow(s, t);

	return 0;
}