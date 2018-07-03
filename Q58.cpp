#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int sLen = s.size();
		if (sLen == 0) return 0;
		int i = 0, j;
		while (s[sLen - i - 1] == ' ' && i < sLen) i++; j = i;
		while (!(s[sLen - i - 1] == ' ') && i<sLen) i++;
		return i-j;
	}
};

int main(void){
	string s = "hello world ";

	Solution model;
	int result = model.lengthOfLastWord(s);

	return 0;
}