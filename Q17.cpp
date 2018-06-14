#include<string>
#include<vector>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		int d_len = digits.size();
		if (d_len == 0) return result;
		vector<string> strs = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<int> lens = { 3, 3, 3, 3, 3, 4, 3, 4 };
		vector<int> map;
		vector<int> idx;
		int sum_idx = 0;

		for (int i = 0; i < d_len; i++){
			int digit = digits[i] - '2';
			map.push_back(digit);
			idx.push_back(lens[digit]-1);
			sum_idx += lens[digit] - 1;
		}

		vector<int> t_idx(d_len, 0);
		while (	1 ){
			string temp;
			for (int i = 0; i < d_len; i++){
				temp += strs[map[i]][t_idx[i]];
			}
			result.push_back(temp);

			if (accumulate(t_idx.begin(), t_idx.end(), 0) == sum_idx) break;
			t_idx[0] += 1;
			for (int i = 0; i < d_len; i++){
				if (t_idx[i] == idx[i]+1 && i<d_len - 1){
					t_idx[i] = 0;
					t_idx[i + 1] += 1;
				}
			}
		}

		return result;
	}


};

int main(void){
	string digits = "23";

	Solution model;
	vector<string> result = model.letterCombinations(digits);

	return 0;
}