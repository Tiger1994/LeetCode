#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s){
		int left = 0, right = s.size() - 1;
		while (left <= right){
			if (s[left] != s[right]) return false;
			left++; right--;
		}

		return true;
	}

	void helper(string s, vector<string> solution, vector<vector<string>> &res){
		if (s.empty()){
			res.push_back(solution);
			return;
		}

		stack<char> record;
		string prefix;

		while (!s.empty()){
			prefix += s.substr(0, 1);
			s.erase(0, 1);
			if (isPalindrome(prefix)){
				solution.push_back(prefix);
				helper(s, solution, res);
				solution.erase(solution.end() - 1);
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		helper(s, {}, res);
		return res;
	}
};

int main(void){
	string s = "fff";

	Solution model;
	vector<vector<string>> res = model.partition(s);

	return 0;
}