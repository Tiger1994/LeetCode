#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v;
		for (int i = 0; i <= rowIndex; i++){
			v.push_back(1);
			if (i <= 1) continue;
			int pre = 1;
			for (int j = 1; j < v.size() - 1; j++){
				int temp = v[j];
				v[j] = pre + v[j];
				pre = temp;
			}
		}

		return v;
	}
};
int main(void){
	Solution model;
	vector<int> result = model.getRow(3);

	return 0;
}