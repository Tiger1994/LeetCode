#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = int(dungeon.size())-1, n = int(dungeon[0].size())-1;
		dungeon[m][n] = dungeon[m][n]>=0 ? 1:1-dungeon[m][n];
		for (int i = m - 1; i >= 0; i--) {
			dungeon[i][n] = max(1, dungeon[i + 1][n] - dungeon[i][n]);
		}
		for (int j = n-1; j >= 0; j--) {
			dungeon[m][j] = max(1, dungeon[m][j + 1] - dungeon[m][j]);
		}
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);
			}
		}
		return dungeon[0][0];
	}
};

int main(void) {
	vector<vector<int>> dungeon;
	dungeon = { {-2, -3, 3},
			   {-5, -10, 1},
			   {10, 30, -5} };
	Solution mode;
	int res = mode.calculateMinimumHP(dungeon);
	return 0;
}