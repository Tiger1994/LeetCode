#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int mLen = matrix.size();
		for (int i = 0; i < mLen / 2; i++){
			for (int j = i; j < mLen - i-1; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[mLen - j - 1][i];
				matrix[mLen - j - 1][i] = matrix[mLen - i - 1][mLen - j - 1];
				matrix[mLen - i - 1][mLen - j - 1] = matrix[j][mLen - i - 1];
				matrix[j][mLen - i - 1] = temp;
			}
		}
	}
};

int main(void){
	vector<vector<int>> matrix = { 	{ 1, 2, 3 },
									{ 4, 5, 6 },
									{ 7, 8, 9 } };

	Solution model;
	model.rotate(matrix);

	return 0;
}