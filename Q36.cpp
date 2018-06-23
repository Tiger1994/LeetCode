#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isUnique(vector<char> s){
		int dotNum = count(s.begin(), s.end(), '.');
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());

		if (s.size() + dotNum == 10 && dotNum > 0 || s.size() == 9) return true;
		else return false;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<char>> boardT(9, {});
		for (int i = 0; i < 9; i++){
			if (!isUnique(board[i])) return false;
			for (int j = 0; j < 9; j++) boardT[j].push_back(board[i][j]);
		}

		for (int i = 0; i < 9; i++){
			if (!isUnique(boardT[i])) return false;
		}

		for (int i = 1; i < 8; i = i + 3){
			for (int j = 1; j < 8; j = j + 3){
				vector<char> tempS;
				for (int m = i - 1; m < i + 2; m++)
					for (int n = j - 1; n < j + 2; n++)
						tempS.push_back(board[m][n]);

				if (!isUnique(tempS)) return false;
			}
		}

		return true;
	}
};

int main(void){
	vector<vector<char>> board = { 
	{ '5', '5', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

	Solution model;
	bool result = model.isValidSudoku(board);

	return 0;
}