#include<vector>
using namespace std;

class Solution {
public:
	void findPath(int m, int n, int currM, int currN, int &result){
		if (currM >= m-1 || currN >= n-1){
			result++; return;}

		findPath(m, n, currM + 1, currN, result);
		findPath(m, n, currM, currN + 1, result);}

	int uniquePaths(int m, int n) {
		int result = 0;
		findPath(m, n, 0, 0, result);
		return result;}

	int uniquePaths2(int m, int n){
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];}}

		return dp[m - 1][n - 1];}};

int main(void){
	int m = 7, n = 3;

	Solution model;
	//int result = model.uniquePaths(m, n);
	int result = model.uniquePaths2(m, n);

	return 0;}
