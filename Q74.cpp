#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int left = 0, right = matrix.size()*matrix[0].size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			int rowIdx = mid / matrix[0].size(), colIdx = mid % matrix[0].size();
			if (matrix[rowIdx][colIdx] == target) return true;
			else if (matrix[rowIdx][colIdx] < target) left = mid + 1;
			else right = mid - 1;
		}

		return false;
	}
};

int main(void){
	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}
	};

	Solution model;
	bool result = model.searchMatrix(matrix, 60);

	return 0;
}