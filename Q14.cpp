#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result=strs[0];
		for (int i = 1; i < strs.size(); i++){
			int idx = 0;
			while (idx < result.size() && idx < strs[i].size()){
				if (result[idx] == strs[i][idx]) idx++;
				else break;
			}

			result.erase(idx, result.size() - idx);
		}
		
		return result;
	}
};

int main(void){
	vector<string> strs = { "flower", "flow", "flight" };

	Solution model;
	string result = model.longestCommonPrefix(strs);

	return 0;
}