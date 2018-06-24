#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<bool>> areaMap;
	vector<vector<bool>> rowMap;
	vector<vector<bool>> colMap;

	bool initMaps(vector<vector<char>> board){
		areaMap = vector<vector<bool>>(9, vector<bool>(9, false));
		rowMap = vector<vector<bool>>(9, vector<bool>(9, false));
		colMap = vector<vector<bool>>(9, vector<bool>(9, false));

		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (board[i][j] == '.') continue;
				int digit = board[i][j] - '1';
				int areaIdx = i / 3 + j / 3 * 3;
				if (areaMap[areaIdx][digit] || rowMap[i][digit] || colMap[j][digit]) return false;
				areaMap[areaIdx][digit] = rowMap[i][digit] = colMap[j][digit] = true;
			}
		}

		return true;
	}

	bool fillBoard(vector<vector<char>>& board, int fillNum){
		if (fillNum >= 81) return true;
		int rowFill = fillNum / 9;
		int colFill = fillNum % 9;
		if (board[rowFill][colFill] != '.') return fillBoard(board, fillNum + 1);

		for (int i = 0; i < 9; i++){
			int areaIdx = rowFill / 3 + colFill / 3 * 3;
			int digit = i;
			if (areaMap[areaIdx][digit] || rowMap[rowFill][digit] || colMap[colFill][digit]) continue;
			board[rowFill][colFill] = '1'+i;
			areaMap[areaIdx][digit] = rowMap[rowFill][digit] = colMap[colFill][digit] = true;

			if (fillBoard(board, fillNum + 1)) return true;
			board[rowFill][colFill] = '.';
			areaMap[areaIdx][digit] = rowMap[rowFill][digit] = colMap[colFill][digit] = false;
		}

		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		if (!initMaps(board)) return;
		bool result = fillBoard(board, 0);
	}
};

int main(void){
	vector<vector<char>> board = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

	Solution model;
	model.solveSudoku(board);

	return 0;
}