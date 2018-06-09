#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		const int str_len = s.size();
		vector<vector <bool> > state_map(str_len, vector<bool>(str_len, false));
		int start = -1;
		int max_len = 0;
		for (int i = 0; i < str_len; i++){
			for (int j = 0; j <= i; j++){
				if (i == j){
					state_map[i][j] = true;
				}
				else if (i - j == 1){
					state_map[i][j] = s[i] == s[j];
				}
				else{
					state_map[i][j] = s[i] == s[j] && state_map[i - 1][j + 1];
				}

				if (state_map[i][j] && max_len < (i - j + 1)){
					start = j;
					max_len = i - j + 1;
				}
			}
		}

		return s.substr(start, max_len);
	}
};

int main(void){
	string input = "a";

	Solution model;
	string output = model.longestPalindrome(input);
	
	return 0;
}