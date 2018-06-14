#include<string>
#include<vector>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations_1(string digits) {
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

	vector<string> letterCombinations(string digits) {
		char  phone[10][4] = { { ' ', '\0', '\0', '\0' }, //0
		{ '\0', '\0', '\0', '\0' }, //1
		{ 'a', 'b', 'c', '\0' }, //2
		{ 'd', 'e', 'f', '\0' }, //3
		{ 'g', 'h', 'i', '\0' }, //4
		{ 'j', 'k', 'l', '\0' }, //5
		{ 'm', 'n', 'o', '\0' }, //6
		{ 'p', 'q', 'r', 's' }, //7
		{ 't', 'u', 'v', '\0' }, //8
		{ 'w', 'x', 'y', 'z' }  //9
		};

		vector<string> result;
		if (digits.size() <= 0){
			result.push_back("");
			return result;
		}
		for (int i = 0; i<digits.size(); i++) {
			if (!isdigit(digits[i])) {
				vector<string> r;
				return r;
			}
			int d = digits[i] - '0';
			if (result.size() <= 0){
				for (int j = 0; j<4 && phone[d][j] != '\0'; j++){
					string s;
					s += phone[d][j];
					result.push_back(s);
				}
				continue;
			}
			vector<string> r;
			for (int j = 0; j<result.size(); j++){
				for (int k = 0; k<4 && phone[d][k] != '\0'; k++){
					string s = result[j] + phone[d][k];
					//sort(s.begin(), s.end());
					r.push_back(s);
				}
			}
			result = r;
		}
		//sort(result.begin(), result.end());

		return result;
	}
};

int main(void){
	string digits = "23";

	Solution model;
	vector<string> result = model.letterCombinations(digits);

	return 0;
}