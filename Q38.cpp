#include<string>
using namespace std;

class Solution {
public:
	string recurse(string s){
		if (s.size() == 0) return "1";
		string result;
		int count = 1;
		while (s.size() > 0){
			if (s.size() >= 2 && s[0] == s[1]){
				s.erase(0, 1); count++;
			}
			else{
				result += count + '0'; result += s[0];
				s.erase(0, 1); count = 1;
			}
		}

		return result;
	}

	string countAndSay(int n) {
		string result;
		for (int i = 0; i < n; i++) result = recurse(result);

		return result;
	}
};

int main(void){
	int n = 6;

	Solution model;
	string result = model.countAndSay(n);

	return 0;
}