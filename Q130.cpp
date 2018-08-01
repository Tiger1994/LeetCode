#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
	void floodFill(vector<vector<char>> &board, int row, int col){
		if (board[row][col] != 'O') return;

		int highth = board.size(), width = board[0].size();
		
		queue<vector<int>> BFS;
		BFS.push({ row, col });
		board[row][col] = '#';
		while (!BFS.empty()){
			vector<int> coor = BFS.front();
			BFS.pop();
			int r = coor[0], c = coor[1];
			if (r > 0 && board[r - 1][c] == 'O'){
				BFS.push({ r - 1, c });
				board[r - 1][c] = '#';
			}
			if (r < highth - 1 && board[r + 1][c] == 'O'){
				BFS.push({ r + 1, c });
				board[r + 1][c] = '#';
			}
			if (c > 0 && board[r][c - 1] == 'O'){
				BFS.push({ r, c - 1 });
				board[r][c - 1] = '#';
			}
			if (c < width && board[r][c + 1] == 'O'){
				BFS.push({ r, c + 1 });
				board[r][c + 1] = '#';
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		if (int(board.size()) <= 1 || int(board[0].size()) <= 0) return;
		int highth = board.size(), width = board[0].size();

		// 从board的四周进行FloodFill
		for (int i = 0; i < highth; i++){
			floodFill(board, i, 0);
			floodFill(board, i, width - 1);
		}
		for (int j = 0; j < width; j++){
			floodFill(board, 0, j);
			floodFill(board, highth - 1, j);
		}

		// 将原先记录的'#'转换为'X'
		for (int i = 0; i < highth; i++){
			for (int j = 0; j < width; j++){
				if (board[i][j] == '#')
					board[i][j] = 'O';
				else board[i][j] = 'X';
			}
		}
	}
};

int main(void){
	vector<vector<char>> board = { { 'X', 'X', 'X', 'X' },
	{'X', 'O', 'O', 'X' },
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X' }
};
	Solution model;
	model.solve(board);

	return 0;
}