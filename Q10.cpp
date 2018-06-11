#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	// By recursion
	bool isMatch_1(string s, string p) {
		if (p.size() == 0) return s.size() == 0;

		bool firstMatch = (s[0] == p[0] || p[0] == '.') && s.size() > 0;
		if (p.size() >= 2 && p[1] == '*'){
			string s_temp = s;
			string p_temp = p;
			bool situation1 = false;						
			if (firstMatch) situation1 = this->isMatch_1(s_temp.erase(0, 1), p);
			bool situation2 = this->isMatch_1(s, p_temp.erase(0, 2));			
			return situation1 || situation2;
		}
		else{
			if (firstMatch) return this->isMatch_1(s.erase(0, 1), p.erase(0, 1));
			else return false;
		}
	}

	// By dynamic programming
	bool isMatch(string s, string p){
		int s_len = s.size();
		int p_len = p.size();

		vector<vector<bool>> states(s_len+1, vector<bool>(p_len + 1, false));
		states[s_len][p_len] = true;
		for (int i = s_len; i >= 0; i--){
			for (int j = p_len-1; j >= 0; j--){
				bool last_math = i < s_len && (s[i] == p[j] || p[j] == '.');

				if (j + 1 < p_len && p[j + 1] == '*'){
					bool situation1 = false;
					if (last_math) situation1 = states[i+1][j];
					states[i][j] = states[i][j + 2] || situation1;
				}
				else{
					if (last_math) states[i][j] = states[i + 1][j + 1];
					else states[i][j] = false;
				}
			}
		}

		return states[0][0];
	}
};

int main(void){
	string s = "bi";
	string p = "b*a*";

	Solution model;
	bool result = model.isMatch(s, p);

	return 0;
}