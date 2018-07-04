#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	bool findK(string input, string output, string& result, int& count, int k){
		if (input.size() == 0){
			count++;
			if (count == k){
				result = output; return true;
			}
			return false;
		}

		for (int i = 0; i < input.size(); i++){
			string tempInput = input, tempOutput = output;
			tempOutput += tempInput[i];
			tempInput.erase(i, 1);
			if (findK(tempInput, tempOutput, result, count, k)) return true;
		}

		return false;
	}

	string getPermutation(int n, int k) {
		string input, result;
		for (int i = 0; i < n; i++) input += i+1+'0';
		int count = 0;
		findK(input, {}, result, count, k);
		return result;
	}

	string getPermutation_2(int n, int k) {
		string result, str;
		vector<int> factorial(1, 0); int record = 1;
		for (int i = 1; i <= n; i++){
			str += i + '0';
			record *= i; factorial.push_back(record);
		}

		for (int i = n - 1; i > 0; i--){
			int idx = 0;
			while (k>factorial[i]){
				k -= factorial[i]; idx++;
			}
			result += str[idx]; str.erase(idx, 1);
		}
		result += str[0];

		return result;
	}
};

int main(void){
	int n = 4, k = 9;

	Solution model;
	//string result = model.getPermutation(n, k);
	string result = model.getPermutation_2(n, k);

	return 0;
}