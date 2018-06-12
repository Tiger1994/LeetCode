#include<string>
using namespace std;

class Solution {
public:
	string intToRoman_1(int num) {
		string result;
		while (num > 0){
			if (num / 100 == 9){ num -= 900; result += "CM"; }
			else if(num / 100 == 4){ num -= 400; result += "CD"; }
			if(num / 10 == 9){ num -= 90; result += "XC"; }
			else if (num / 10 == 4){ num -= 40; result += "XL"; }
			if (num == 9){ num -= 9; result += "IX"; }
			else if (num == 4){ num -= 4; result += "IV"; }

			if (num >= 1000) { num -= 1000; result += "M"; }
			else if (num >= 500) { num -= 500; result += "D"; }
			else if (num >= 100) { num -= 100; result += "C"; }
			else if (num >= 50) { num -= 50; result += "L"; }
			else if (num >= 10) { num -= 10; result += "X"; }
			else if (num >= 5) { num -= 5; result += "V"; }
			else if(num >= 1) { num -= 1; result += "I"; }
		}
		
		return result;
	}

	string intToRoman(int num) {
		string result;
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

		for (int i = 0; num; i++){
			while (num){
				if (num >= value[i]){
					num -= value[i];
					result += symbol[i];
				}
				else break;
			}
		}

		return result;
	}
};

int main(void){
	int num = 100;

	Solution model;
	string result = model.intToRoman(num);

	return 0;
}