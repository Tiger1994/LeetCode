#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, int> strMap;
		int mapIdx = 0;
		vector<vector<string>> result;
		for (int i = 0; i < strs.size(); i++){
			string tempS = strs[i];
			sort(tempS.begin(), tempS.end());
			if (strMap.find(tempS) != strMap.end()){
				result[strMap[tempS]].push_back(strs[i]);
			}
			else{
				strMap.insert(make_pair(tempS, mapIdx));
				result.push_back({});
				result[mapIdx].push_back(strs[i]);
				mapIdx++;
			}
		}

		return result;
	}
};

int main(void){
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

	Solution model;
	vector<vector<string>> result = model.groupAnagrams(strs);

	return 0;
}