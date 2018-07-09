#include<vector>
using namespace std;

class Solution {
public:
	bool searchOne(vector<vector<char>> board, int row, int col, string rest){
		if (rest.size() == 0) return true;
		int rowLen = board.size(), colLen = board[0].size();
		vector<vector<int>> newIdx = { { row - 1, col }, { row + 1, col }, { row, col - 1 }, { row, col + 1 } };
		for (auto idx : newIdx){
			if (idx[0] >= 0 && idx[0] < rowLen && idx[1] >= 0 && idx[1] < colLen && board[idx[0]][idx[1]] == rest[0]){
				char tempChar = board[idx[0]][idx[1]]; board[idx[0]][idx[1]] = '.';
				string tempRest = rest; tempRest.erase(0, 1);
				if (searchOne(board, idx[0], idx[1], tempRest)) return true;
				board[idx[0]][idx[1]] = tempChar;
			}
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[0].size(); j++){
				if (board[i][j] == word[0]){
					char tempChar = board[i][j]; board[i][j] = '.';
					string tempRest = word; tempRest.erase(0, 1);
					if (searchOne(board, i, j, tempRest)) return true;
					board[i][j] = tempChar;
				}
			}
		}

		return false;
	}
};

int main(void){
	vector<vector<char>> board = {
		    {'A', 'B', 'C', 'E'},
			{'S', 'F', 'C', 'S'},
			{'A', 'D', 'E', 'E'}
	};
	string word = "SEE";

	Solution model;
	bool result = model.exist(board, word);

	return 0;
}