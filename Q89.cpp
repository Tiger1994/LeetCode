#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		string grayCode(n, '0');
		vector<int> result;
		unordered_map<string, int> records;
		result.push_back(0);
		records[grayCode]++;
		int total = int(pow(2, n));
		for (int i = 0; i < total; i++){			
			for (int j = 0; j < n; j++){
				string temp = grayCode;
				temp[j] = temp[j] == '0' ? '1' : '0';
				if (records[temp] == 0){
					records[temp]++;
					int num = strtol(temp.data(), NULL, 2);
					result.push_back(num);
					grayCode = temp;
					break;
				}
			}
		}

		return result;
	}

	vector<int> grayCode2(int n){
		vector<int> result;
		int size = 1 << n;
		for (int i = 0; i < size; i++){
			result.push_back((i >> 1) ^ i);
		}
		return result;
	}
};

int main(void){
	Solution model;
	vector<int> result = model.grayCode2(2);


	return 0;
}