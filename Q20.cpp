#include<string>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid_1(string s) {
		if (s.size() % 2) return false;

		map<char, char> pairs;
		pairs.insert(pair<char, char>('{', '}'));
		pairs.insert(pair<char, char>('[', ']'));
		pairs.insert(pair<char, char>('(', ')'));
		
		while (s.size()){
			int idx = 0;
			int s_len = s.size();
			for (int i = 0; i < s_len-1; i++){
				if (pairs[s[i]] == s[i + 1]){
					s.erase(i, 2);
					break;
				}
			}

			if (s_len == s.size()) break;
		}

		if (s.size()) return false;
		else return true;
	}

	bool isValid(string s){
		if (s.size() % 2) return false;
		map<char, char> pairs;
		pairs.insert(pair<char, char>('{', '}'));
		pairs.insert(pair<char, char>('[', ']'));
		pairs.insert(pair<char, char>('(', ')'));

		stack<char> strs;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '{' || s[i] == '[' || s[i] == '('){
				strs.push(s[i]);
			}
			else {
				if (strs.empty()) return false;
				if (pairs[strs.top()] == s[i] || pairs[strs.top()] == s[i] || pairs[strs.top()] == s[i]){
					strs.pop();
				}
				else return false;
			}
		}

		return strs.empty();
	}
};

int main(void){
	string s = "{[}]";

	Solution model;
	bool result = model.isValid(s);

	return 0;
}