#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea_1(vector<int>& height) {
		int result = 0;
		for (int i = 0; i < height.size() - 1; i++){
			for (int j = i + 1; j < height.size(); j++){
				result = max(result, min(height[i], height[j])*(j - i));
			}
		}

		return result;
	}

	int maxArea(vector<int>& height) {
		int result = 0;
		int start = 0, end = height.size()-1;
		while (start < end){
			result = max(result, min(height[start], height[end])*(end - start));
			if (height[start] > height[end]) end--;
			else start++;
		}

		return result;
	}
};

int main(void){
	Solution model;
	vector<int> height;
	height.push_back(10);
	height.push_back(10);
	height.push_back(10);

	int result = model.maxArea(height);
	return 0;
}