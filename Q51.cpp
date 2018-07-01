#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	void recurse(vector<string> solution, int pos, vector<vector<bool>> validPos, vector<vector<string>>& result){
		int n = solution[0].size();
		if (pos == n){
			result.push_back(solution); return;
		}

		for (int i = 0; i < n; i++){
			if (!validPos[pos][i]) continue;

			vector<vector<bool>> newPos = validPos;
			for (int j = pos; j < n; j++){
				newPos[j][i] = false;
				if (i - j + pos >= 0) newPos[j][i - j + pos] = false;
				if (i + j - pos < n) newPos[j][i + j - pos] = false;
			}
			solution[pos][i] = 'Q';

			recurse(solution, pos + 1, newPos, result);
			solution[pos][i] = '.';
		}

		return;
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> solution(n, string(n, '.'));
		vector<vector<bool>> validPos = vector<vector<bool>>(n, vector<bool>(n, true));

		recurse(solution, 0, validPos, result);

		return result;
	}
};

int main(void){
	int n = 5;

	Solution model;
	vector<vector<string>> result = model.solveNQueens(n);

	return 0;
}