#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0) return result;
		int rows = matrix.size(), cols = matrix[0].size();
		if (rows == 1){
			for (int i = 0; i < cols; i++) result.push_back(matrix[0][i]);
			return result;
		}
		if (cols == 1){
			for (int i = 0; i < rows; i++) result.push_back(matrix[i][0]);
			return result;
		}

		for (int i = 0; i < min(rows, cols) / 2; i++){
			for (int j = i; j < cols - i - 1; j++){
				result.push_back(matrix[i][j]);
			}
			for (int j = i; j < rows - i - 1; j++){
				result.push_back(matrix[j][cols-i-1]);
			}
			for (int j = i; j < cols - i - 1; j++){
				result.push_back(matrix[rows-i-1][cols - j - 1]);
			}
			for (int j = i; j < rows - i - 1; j++){
				result.push_back(matrix[rows - j - 1][i]);
			}
		}

		if (cols >= rows && rows % 2){
			for (int i = rows / 2; i < cols - rows/2; i++){
				result.push_back(matrix[rows/2][i]);
			}
		}

		else if (cols < rows && cols % 2){
			for (int i = cols / 2; i < rows - cols/2; i++){
				result.push_back(matrix[i][cols/2]);
			}
		}
		return result;
    }

	vector<int> spiralOrder_2(vector<vector<int>>& matrix){
		vector<int> result; if (matrix.size() == 0) return result;
		int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
		while (left <= right && top <= bottom){
			for (int i = left; i < right; i++) result.push_back(matrix[top][i]);
			for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
			if (left < right && top < bottom){
				for (int i = right - 1; i > left; i--) result.push_back(matrix[bottom][i]);
				for (int i = bottom; i > top; i--) result.push_back(matrix[i][left]);
			}
			left++, right--, top++, bottom--;
		}

		return result;
	}
};

int main(void){
	vector<vector<int>> matrix = {  { 1, 2, },
									{ 5, 6, },
									{ 9, 10 } };

	vector<vector<int>> matrix2 = { { 1 }, { 2 }, { 3 } };
	vector<vector<int>> matrix3 = { { 1, 2, 3 } };
	Solution model;
	//vector<int> result = model.spiralOrder(matrix);
	vector<int> result = model.spiralOrder_2(matrix3);

	return 0;
}