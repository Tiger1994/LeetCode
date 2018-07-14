#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	void recurse(string s, vector<int> solution, vector<string> &result){
		if (solution.size() == 4){
			if (s.size()) return;
			string str;
			for (int i = 0; i < 3; i++){
				str += to_string(solution[i]) + ".";
			}
			str += to_string(solution[3]);
			result.push_back(str);
			return;
		}
		
		for (int i = 0; i < 3 && i < s.size(); i++){
			if (i>0 && s[0] == '0') continue;
			int value = stoi(s.substr(0, i + 1));
			if (value >= 0 && value <= 255){
				string tempS = s; vector<int> tempSolution = solution;
				tempS.erase(0, i + 1); tempSolution.push_back(value);
				recurse(tempS, tempSolution, result);
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		recurse(s, {}, result);

		return result;
	}
};

int main(void){
	string s = "010010";

	Solution model;
	vector<string> result = model.restoreIpAddresses(s);

	return 0;
}