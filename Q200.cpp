#include<vector>
using namespace std;

class Solution {
public:
	void helper(vector<vector<char>>& grid, int i, int j) {
		int m = int(grid.size()), n = int(grid[0].size());
		grid[i][j] = '2';
		if (i - 1 >= 0 && grid[i - 1][j] == '1') helper(grid, i - 1, j);
		if (i + 1 < m && grid[i + 1][j] == '1') helper(grid, i + 1, j);
		if (j - 1 >= 0 && grid[i][j - 1] == '1') helper(grid, i, j - 1);
		if (j + 1 < n && grid[i][j + 1] == '1') helper(grid, i, j + 1);
		return;
	}
	int numIslands(vector<vector<char>>& grid) {
		int res(0);
		int m = int(grid.size()), n = int(grid[0].size());
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					res++;
					helper(grid, i, j);
				}
			}
		}
		return res;
	}
};

int main(void) {
	vector<vector<char>> grid = { {'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'} };
	Solution mode;
	int res = mode.numIslands(grid);
	return 0;
}