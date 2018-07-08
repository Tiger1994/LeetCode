#include<vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rowLen = matrix.size(), colLen = matrix[0].size();
		bool firstRow, firstCol;
		for (int i = 0; i < rowLen; i++){
			if (matrix[i][0] == 0){
				firstRow = true; break;
			}
		}
		for (int j = 0; j < colLen; j++){
			if (matrix[0][j] == 0){
				firstCol = true; break;
			}
		}
		for (int i = 1; i < rowLen; i++){
			for (int j = 1; j < colLen; j++){
				if (!matrix[i][j]){
					matrix[i][0] = 0; matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < rowLen; i++){
			if (!matrix[i][0]){
				for (int j = 1; j < colLen; j++)
					matrix[i][j] = 0;
			}
		}

		for (int j = 1; j < colLen; j++){
			if (!matrix[0][j]){
				for (int i = 1; i < rowLen; i++)
					matrix[i][j] = 0;
			}
		}

		if (firstRow){
			for (int i = 0; i < rowLen; i++)
				matrix[i][0] = 0;
		}
		if (firstCol){
			for (int j = 0; j < colLen; j++)
				matrix[0][j] = 0;
		}
	}
};

int main(void){
	vector<vector<int>> matrix = 
	{
		{0, 1, 2, 0},
		{3, 0, 5, 2},
		{1, 3, 1, 5}
	};

	Solution model;
	model.setZeroes(matrix);

	return 0;
}