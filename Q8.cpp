#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 0) return 0;

		while (str[0] == ' ') str.erase(0,1);
		if (str.size() == 0) return 0;
		
		int symbol = 1;
		if (str[0] == '-'){
			symbol = -1;
			str.erase(0, 1);
		}
		else if (str[0] == '+'){
			str.erase(0, 1);
		}
		if (str.size() == 0) return 0;

		double result=0;
		if (str[0] > '9' || str[0] < '0') return 0;
		while (str[0] <= '9' && str[0] >= '0'){
			int digit = str[0] - '0';
			result = result * 10 + symbol*digit;
			if (result >= INT_MAX) return INT_MAX;
			else if (result <= INT_MIN) return INT_MIN;
			
			str.erase(0, 1);
			if (str.size() == 0) break;
		}

		return int(result);
	}
};

int main(void){
	string input = "-91283472332";

	Solution model;
	int output = model.myAtoi(input);

	return 0;
}