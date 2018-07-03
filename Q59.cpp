#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int left = 0, right = n - 1, top = 0, bottom = n - 1;
		int count = 1;
		while (left <= right){
			for (int i = left; i <= right; i++) result[top][i] = count++;
			if (left < right){
				for (int i = top + 1; i < bottom; i++) result[i][right] = count++;
				for (int i = right; i > left; i--) result[bottom][i] = count++;
				for (int i = bottom; i > top; i--) result[i][left] = count++;
			}
			left++; right--; top++; bottom--;
		}

		return result;
	}
};

int main(void){
	int n = 3;

	Solution model;
	vector<vector<int>> result = model.generateMatrix(n);

	return 0;
}