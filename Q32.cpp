#include<string>
#include<vector>
#include<numeric>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses_1(string s) {
		int sLen = s.size();
		if (sLen < 2) return 0;

		vector<int> record(sLen, 0);
		int maxLen = 0;

		for (int i = 1; i < s.size(); i++){
			if (s[i] == ')' && s[i - 1] == '('){
				if (i - 2 >= 0) record[i] = record[i - 2] + 2;
				else record[i] = 2;
				maxLen = max(maxLen, record[i]);
			}
			else if (s[i] == ')' && s[i - 1] == ')'){
				if (i - record[i - 1] - 1 >= 0 && s[i - record[i - 1] - 1] == '('){
					if (i - record[i - 1] - 2 >= 0) record[i] = record[i - 1] + record[i - record[i - 1] - 2] + 2;
					else record[i] = record[i - 1] + 2;
					maxLen = max(maxLen, record[i]);
				}
			}
		}

		return maxLen;
	}

	int longestValidParentheses_2(string s){
		int sLen = s.size();
		if (sLen < 2) return 0;
		stack<int> record;
		record.push(-1);
		int maxLen = 0;

		for (int i = 0; i < sLen; i++){
			if (s[i] == '(') record.push(i);
			else{
				record.pop();
				if (record.empty()) record.push(i);
				else maxLen = max(maxLen, i - record.top());
			}
		}

		return maxLen;
	}
};

int main(void){
	string s = ")()";

	Solution model;
	//int result = model.longestValidParentheses_1(s);
	int result = model.longestValidParentheses_2(s);

	return 0;
}