#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void helper(vector<vector<int>> triangle, int layer, int pos, vector<int> solution, int sum, int &minVal){
		if (triangle.size() == solution.size()){
			minVal = min(sum, minVal);
			return;
		}
		
		vector<int> tempSolution = solution;
		int tempSum = sum;
		tempSolution.push_back(triangle[layer][pos]);
		tempSum += triangle[layer][pos];
		helper(triangle, layer+1, pos, tempSolution, tempSum, minVal);

		if (layer >= 1){
			vector<int> tempSolution = solution;
			int tempSum = sum;
			tempSolution.push_back(triangle[layer][pos + 1]);
			tempSum += triangle[layer][pos + 1];
			helper(triangle, layer+1, pos+1, tempSolution, tempSum, minVal);
		}
	}

	int minimumTotal(vector<vector<int>>& triangle) {
		int minVal = INT_MAX;
		helper(triangle, 0, 0, {}, 0, minVal);
		return minVal;
	}

	int minimumTotal2(vector<vector<int>>& triangle){
		if (triangle.size() == 1) return triangle[0][0];
		for (int i = 1; i < triangle.size(); i++){
			for (int j = 0; j < triangle[i].size(); j++){
				if (j == 0) triangle[i][j] += triangle[i - 1][j];
				else if (j == (triangle[i].size() - 1))
					triangle[i][j] += triangle[i - 1].back();
				else if (i>1)
					triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}

		int minVal = *min_element(triangle.back().begin(), triangle.back().end());
		return minVal;
	}
};

int main(void){
	vector<vector<int>> triangle = { 
	{2 },
	{ 3, 4 },
	{ 6, 5, 7 },
	{ 4, 1, 8, 3 }
	};

	Solution model;
	int result = model.minimumTotal2(triangle);

	return 0;
}