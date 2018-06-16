#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> counts_old;
	vector<string> addParathese(vector<string> input, int idx, int end){
		vector<string> result;
		vector<int> counts;

		if (input.size() == 0){
			result.push_back("(");
			counts_old.push_back(1);
			return result;
		}

		for (int i = 0; i < input.size(); i++){
			if (counts_old[i] < end && input[i].size() < end * 2 - 1){
				counts.push_back(counts_old[i]+1);
				result.push_back(input[i] + "(");
			}
			if (input[i].size() - counts_old[i] < counts_old[i]){
				result.push_back(input[i] + ")");
				counts.push_back(counts_old[i]);
			}
		}

		counts_old = counts;
		return result;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0) return result;
		if (n == 1){
			result.push_back("()");
			return result;
		}

		for (int i = 0; i < n * 2; i++){
			result = addParathese(result, i, n);
		}

		return result;
	}


	vector<string> result;
	void backtrack(string s, int left, int right, int n){
		if (s.size() == n * 2){
			result.push_back(s);
			return;
		}
		if (left < n) backtrack(s + "(", left + 1, right, n);
		if (left > right) backtrack(s + ")", left, right + 1, n);
	}

	vector<string> generateParenthesis_1(int n){
		backtrack("", 0, 0, n);
		return result;
	}

	vector<string> generateParenthesis_2(int n){
		vector<string> result;
		
		if (n == 0){
			result.push_back("");
			return result;
		}

		for (int i = 0; i < n; i++){
			vector<string> left = this->generateParenthesis_2(i);
			vector<string> right = this->generateParenthesis_2(n - i - 1);
			for (int j = 0; j < left.size(); j++){
				for (int k = 0; k < right.size(); k++){
					result.push_back("(" + left[j] + ")" + right[k]);
				}
			}
		}

		return result;
	}
};

int main(void){
	int n = 1;

	Solution model;
	vector<string> result = model.generateParenthesis_2(n);

	return 0;
}