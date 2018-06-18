#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag;
		double dividend_d = dividend, divisor_d = divisor;
		if (dividend_d >= 0 && divisor_d >= 0) flag = 1;
		else if (dividend_d >= 0 && divisor_d < 0) flag = -1, divisor_d = -divisor_d;
		else if (dividend_d < 0 && divisor_d>0) flag = -1, dividend_d = -dividend_d;
		else flag = 1, dividend_d = -dividend_d, divisor_d = -divisor_d;

		double result = 0;
		double sum = divisor_d;
		while (dividend_d >= sum){
			sum += divisor_d;
			result += flag;
		}
		if (result >= INT_MAX) return INT_MAX;
		if (result <= INT_MIN) return INT_MIN;
		return int(result);
	}

	int divide_2(int dividend, int divisor) {
		bool flag;
		long long dvd_abs, dvs_abs;
		if (dividend >= 0 && divisor >= 0) flag = true;
		else if (dividend >= 0 && divisor < 0) flag = false;
		else if (dividend < 0 && divisor >= 0) flag = false;
		else flag = true;

		unsigned int temp1 = dvd_abs = (dividend >= 0 ? dividend : -dividend);
		unsigned int temp2 = dvs_abs = divisor >= 0 ? divisor : -divisor;
		dvd_abs = temp1;
		dvs_abs = temp2;

		vector<unsigned int> value_record;
		unsigned long long value = 1;
		while (dvd_abs >= dvs_abs){
			value_record.push_back(dvs_abs);
			dvs_abs = dvs_abs << 1;
		}

		long long result = 0;
		unsigned int one = 1;
		for (int i = value_record.size() - 1; i >= 0; i--){
			if (dvd_abs >= value_record[i]) {
				result += one << i;
				dvd_abs -= value_record[i];
			}
		}

		if (!flag) result = 0 - result;

		if (result >= INT_MAX) return INT_MAX;
		else if (result <= INT_MIN) return INT_MIN;
		else return int(result);
	}
};

int main(void){
	int dividend = INT_MIN, divisor = 2;

	Solution model;
	//int result = model.divide(dividend, divisor);
	int result = model.divide_2(dividend, divisor);

	return 0;
}