#include<string>
using namespace std;

class Solution {
public:
	bool isLetter(char c){
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
		else return false;
	}
	bool isNumeric(char c){
		if (c >= '0' && c <= '9')
			return true;
		else return false;
	}

	bool isPalindrome(string s) {
		int left = 0, right = s.size()-1;
		int offset = 'A' - 'a';
		while (left <= right){
			if (!isLetter(s[left]) && !isNumeric(s[left])){
				left++;
				continue;
			}
			if (!isLetter(s[right]) && !isNumeric(s[right])){
				right--;
				continue;
			}

			if (isNumeric(s[left]) || isNumeric(s[right])){
				if (s[left] == s[right]){
					left++;
					right--;
					continue;
				}
				else return false;
			}

			if (s[left] == s[right] || s[left] == s[right] + offset || s[left] == s[right] - offset){
				left++;
				right--;
				continue;
			}
			else return false;
		}

		return true;
	}
};

int main(void){
	string s = "A man, a plan, a canal: Panama";
	Solution model;
	bool result = model.isPalindrome(s);
	return 0;
}