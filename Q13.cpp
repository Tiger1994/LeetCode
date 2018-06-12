#include<string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		for (int i = 0; s.size(); i++){
			while (s.size()){
				int idx = s.find(symbol[i]);
				if (idx == 0){
					s.erase(0, symbol[i].size());
					result += value[i];
				}
				else break;
			}
		}

		return result;
	}
};

int main(void){
	string s = "MCMXCIV";

	Solution model;
	int result = model.romanToInt(s);

	return 0;
}