#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	// 运用题目的周期性
	string convert_1(string s, int numRows) {	
		if (numRows == 1){
			return s;
		}
		int str_len = s.size();
		vector<string > str_matrix;
		for (int i = 0; i < numRows; i++){
			str_matrix.push_back("");
		}

		for (int i = 0; i < str_len; i++){
			int row_idx = i % (2 * numRows - 2);
			if (row_idx >= numRows){
				row_idx = 2 * numRows - 2 - row_idx;
			}
			str_matrix[row_idx] += s[i];
		}

		string result = "";
		for (int i = 0; i < numRows; i++){
			result += str_matrix[i];
		}

		return result;
	}

	// 用爬楼梯的方法
	string convert(string s, int numRows){
		int str_len = s.size();
		if (numRows == 1 || str_len <= numRows) return s;

		vector<string> strs(numRows);
		int row_idx = 0;
		int step = 1;
		for (int i = 0; i < str_len; i++){
			if (row_idx == numRows - 1) step = -1;
			if (row_idx == 0) step = 1;
			strs[row_idx] += s[i];
			row_idx += step;
		}

		string result;
		for (int i = 0; i < numRows; i++){
			result += strs[i];
		}

		return result;
	}
};

int main(void){
	string s = "P";
	int numRows = 2;

	Solution model;
	string result = model.convert(s, numRows);

	return 0;
}