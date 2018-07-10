#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	void getMaxRec(vector<int> heights, int &maxRec){
		if (heights.size() == 0) return;
		auto minHeight = min_element(heights.begin(), heights.end());
		int rec = *minHeight*heights.size();
		maxRec = max(maxRec, rec);
		int minIdx = distance(heights.begin(), minHeight);
		if (heights.size() == 1) return;

		vector<int> leftHeights, rightHeights;
		leftHeights.assign(heights.begin(), heights.begin() + minIdx);
		getMaxRec(leftHeights, maxRec);
		rightHeights.assign(heights.begin()+minIdx+1, heights.end());
		getMaxRec(rightHeights, maxRec);
	}
	int largestRectangleArea(vector<int>& heights) {
		int maxRec = 0;
		getMaxRec(heights, maxRec);
		return maxRec;
	}

	int largestRectangleArea2(vector<int>& heights){
		stack<int> records; int maxRec = 0;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++){
			if (records.size() == 0 || heights[records.top()] <= heights[i]){
				records.push(i); continue;
			}

			int top = records.top(); records.pop();
			int rec = records.size() ? (i - records.top()-1)*heights[top] : i*heights[top];
			maxRec = max(maxRec, rec);
			i--;
		}

		return maxRec;
	}
};

int main(void){
	vector<int> heights = { 2, 1, 5, 6, 2, 3 };

	Solution model;
	int result = model.largestRectangleArea2(heights);

	return 0;
}