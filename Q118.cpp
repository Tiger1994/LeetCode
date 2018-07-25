#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		for (int i = 0; i < numRows; i++){
			vector<int> v(i + 1, 1);
			if (i < 2){
				vv.push_back(v);
				continue;
			}
			for (int j = 1; j < v.size()-1; j++){
				v[j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
			vv.push_back(v);
		}

		return vv;
	}
};

int main(void){
	Solution model;
	vector<vector<int>> result = model.generate(3);

	return 0;
}