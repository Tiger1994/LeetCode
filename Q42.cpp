#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	int trap_1(vector<int>& height) {
		int result = 0;
		for (int i = 0; i < height.size(); i++){
			int leftMax = *max_element(height.begin(), height.begin()+i+1);
			int rightMax = *max_element(height.begin() + i, height.end());
			result += min(leftMax, rightMax) - height[i];
		}

		return result;
	}

	int trap_2(vector<int>& height){
		if (height.size() < 3) return 0;
		int hLen = height.size(), result = 0;
		vector<int> leftMax(hLen), rightMax(hLen);
		leftMax[0] = height[0]; rightMax[hLen - 1] = height[hLen - 1];
		for (int i = 1; i < hLen; i++) leftMax[i] = max(height[i], leftMax[i - 1]);
		for (int i = hLen - 2; i >= 0; i--) rightMax[i] = max(height[i], rightMax[i + 1]);
		
		for (int i = 0; i < hLen; i++) result += min(leftMax[i], rightMax[i]) - height[i];

		return result;
	}

	int trap_3(vector<int>& height){
		if (height.size() < 3) return 0;
		stack<int> locs; locs.push(0);
		int result = 0, curr = 1;
		while (curr < height.size()){
			while (!locs.empty() && height[curr] > height[locs.top()]){
				int top = locs.top();
				locs.pop();
				if (locs.empty()) break;
				int distance = curr - locs.top() - 1;
				int boundH = min(height[locs.top()], height[curr]) - height[top];
				result += distance*boundH;
			}
			locs.push(curr++);
		}		

		return result;
	}

	int trap_4(vector<int>& height){
		if (height.size() < 3) return 0;
		int leftMax = 0, rightMax = 0, left = 0, right = height.size() - 1;
		int result = 0;
		while (left <= right){
			if (leftMax <= rightMax){
				if (height[left] < leftMax)	result += leftMax - height[left++];
				else leftMax = height[left++];
			}
			else{
				if (height[right] < rightMax) result += rightMax - height[right--];
				else rightMax = height[right--];
			}
		}

		return result;
	}
};

int main(void){
	vector<int> height = { 2, 0, 2 };

	Solution model;
	//int result = model.trap_1(height);
	//int result = model.trap_2(height);
	//int result = model.trap_3(height);
	int result = model.trap_4(height);

	return 0;
}