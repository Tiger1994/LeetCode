#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
	int helper(vector<int>& prices, int left, int right){
		if (right-left < 1) return 0;
		int maxPro = 0, left_in = left, right_in = left;
		while (right_in <= right){
			if (prices[right_in] <= prices[left_in]){
				left_in = right_in;
				right_in++;
			}
			else{
				maxPro = max(maxPro, prices[right_in] - prices[left_in]);
				right_in++;
			}
		}

		return maxPro;
	}

	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		if (prices.size() < 4) return helper(prices, 0, prices.size()-1);

		int maxPro = 0;
		for (int i = 1; i < prices.size()-1; i++){
			maxPro = max(maxPro, helper(prices, 0, i) + helper(prices, i+1, prices.size()-1));
		}

		return maxPro;
	}

	int maxProfit2(vector<int>& prices){
		vector<vector<int>> global(prices.size(), vector<int>(3, 0));
		vector<vector<int>> local(prices.size(), vector<int>(3, 0));
		for (int i = 1; i < prices.size(); i++){
			int diff = prices[i] - prices[i - 1];
			for (int j = 1; j < 3; j++){
				local[i][j] = max(global[i - 1][j-1] + max(0, diff), local[i - 1][j] + diff);
				global[i][j] = max(global[i - 1][j], local[i][j]);
			}
		}

		return global[prices.size() - 1][2];
	}
};

int main(void){
	vector<int> prices = { 3, 3, 5, 0, 0, 3, 1, 4 };

	Solution model;
	int result = model.maxProfit2(prices);

	return 0;
}