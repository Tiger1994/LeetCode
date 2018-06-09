#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> show_now;
		int max_rep = 0;
		int rep_pos = -1;
		for (int idx = 0; idx < s.size(); idx++){
			if (show_now.find(s[idx]) != show_now.end() && rep_pos < show_now[s[idx]]){
				rep_pos = show_now[s[idx]];
			}
			if (idx - rep_pos > max_rep){
				max_rep = idx - rep_pos;
			}
			show_now[s[idx]] = idx;
		}
		return max_rep;
	}
};

int main(void){
	string input = "a";
	Solution model;
	int length = model.lengthOfLongestSubstring(input);

	return 0;
}