#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights){
		stack<int> records; int maxRec = 0;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++){
			if (records.size() == 0 || heights[records.top()] <= heights[i]){
				records.push(i); continue;
			}

			int top = records.top(); records.pop();
			int rec = records.size() ? (i - records.top() - 1)*heights[top] : i*heights[top];
			maxRec = max(maxRec, rec);
			i--;
		}

		return maxRec;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		vector<int> heights(matrix[0].size(), 0);
		int maxRec = 0;
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[0].size(); j++){
				if (matrix[i][j] == '1'){
					heights[j] += 1;
				}
				else heights[j] = 0;
			}
			int rec = largestRectangleArea(heights);
			maxRec = max(maxRec, rec);
		}
		return maxRec;
	}
};

int main(void){
	vector<vector<char>> matrix = {
		    {'1', '0', '1', '0', '0'},
			{'1', '1', '1', '1', '1'},
			{'1', '1', '0', '1', '1'},
			{'1', '0', '0', '1', '0'}
	};

	Solution model;
	int result = model.maximalRectangle(matrix);

	return 0;
}