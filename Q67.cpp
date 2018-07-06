#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		while (a.size() != b.size()){
			if (a.size() > b.size()) b.insert(b.begin(), '0');
			else a.insert(a.begin(), '0');
		}
		int carryBit = 0;
		for (int i = a.size()-1; i >= 0; i--){
			int tSum = a[i] - '0' + b[i] - '0'+carryBit;
			a[i] = tSum % 2 + '0'; carryBit = tSum / 2;
		}
		if (carryBit) a.insert(a.begin(), '1');
		return a;
	}
};

int main(void){
	string a = "11";
	string b = "1";

	Solution model;
	string result = model.addBinary(a, b);

	return 0;
}