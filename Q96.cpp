#include<vector>
#include<stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int helper(int low, int high){
		int res = 0;
		if (low >= high) return 1;

		for (int i = low; i <= high; i++){
			int leftNum = helper(low, i - 1);
			int rightNum = helper(i + 1, high);
			for (int left = 0; left < leftNum; left++){
				for (int right = 0; right < rightNum; right++){
					res++;
				}
			}
		}

		return res;
	}

	int numTrees(int n) {
		if (n == 0) return 0;
		return helper(1, n);
	}

	int numTrees2(int n) {
		vector<int> dp(n+1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 0; j < i; j++){
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}

		return dp[n];
	}
};

int main(void){
	Solution model;
	int result = model.numTrees2(6);

	return 0;
}