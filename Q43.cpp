#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string sum2string(string num1, string num2){
		if (num1.size() == 0) return num2;
		string result;
		int carryBit = 0;
		while(num1.size() && num2.size()){
			int S = num1[0] -  '0' + num2[0] - '0' + carryBit;
			result.push_back(S % 10 + '0');
			carryBit = S / 10;
			num1.erase(0, 1); num2.erase(0, 1);
		}

		if (num1.size()){
			while (num1.size()){
				int S = num1[0] - '0' + carryBit;
				result.push_back(S % 10 + '0');
				carryBit = S / 10;
				num1.erase(0, 1);
			}
		}
		else{
			while (num2.size()){
				int S = num2[0] - '0' + carryBit;
				result.push_back(S % 10 + '0');
				carryBit = S / 10;
				num2.erase(0, 1);
			}
		}
		if (carryBit > 0) result.push_back(carryBit + '0');

		return result;
	}

	string multiply(string num1, string num2) {
		if ((num1.size() == 1 && num1[0] == '0') && (num2.size() == 1 && num2[0] == '0')) return "0";
		string result;
		for (int i = num2.size()-1; i >= 0; i--){
			string bitM;
			for (int j = 0; j < num2.size() - i - 1; j++) bitM.push_back('0');
			int carryBit = 0, digit2 = num2[i] - '0';
			for (int j = num1.size() - 1; j >= 0; j--){
				int digit1 = num1[j] - '0';
				int M = digit1*digit2 + carryBit;
				bitM.push_back(M % 10+'0');
				carryBit = M / 10;
			}
			if (carryBit > 0) bitM.push_back(carryBit + '0');

			result = sum2string(result, bitM);
		}

		reverse(result.begin(), result.end());
		return result;
	}
};

int main(void){
	string num1 = "1", num2 = "0";

	Solution model;
	string result = model.multiply(num1, num2);

	return 0;
}