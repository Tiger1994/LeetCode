#include<vector>
using namespace std;

class Solution {
public:
	void addOne(vector<int> in, vector<int> out, vector<vector<int>> &result, int k){
		if (out.size() == k){
			result.push_back(out);
			return;
		}
		for (int i = 0; i < in.size(); i++){
			vector<int> tempIn = in;
			vector<int> tempOut = out;
			tempIn.erase(tempIn.begin(), tempIn.begin()+i+1);
			tempOut.push_back(in[i]);
			addOne(tempIn, tempOut, result, k);
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> in; vector<vector<int>> result;
		for (int i = 0; i < n; i++) in.push_back(i + 1);
		addOne(in, {}, result, k);
		return result;
	}

	vector<vector<int>> combine2(int n, int k){
		vector<int> ones(n), lib(n); vector<vector<int>> result;
		for (int i = 0; i < n; i++){
			ones[i] = (i < k) ? 1 : 0; lib[i] = i+1;
		}
		while (1){
			vector<int> solution; bool flag = false;
			for (int i = 0; i < n; i++){
				if (ones[i]) solution.push_back(lib[i]);
			}
			result.push_back(solution);
			int count = 0;
			for (int i = 0; i < n - 1; i++){
				if (ones[i] == 1 && ones[i + 1] == 0){
					flag = true;
					ones[i] = 0; ones[i + 1] = 1;
					for (int j = 0; j < i; j++){
						ones[j] = count-->0 ? 1 : 0;
					}
					break;
				}
				else if (ones[i]) count++;
			}
			if (!flag) break;
		}

		return result;
	}
};

int main(void){
	Solution model;
	vector<vector<int>> result = model.combine2(4, 2);

	return 0;
}