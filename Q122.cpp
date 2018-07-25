#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int maxPro = 0;
		int buy = INT_MAX;
		for (int i = 0; i < prices.size(); i++){
			if (buy>prices[i]) buy = prices[i];
			if (prices[i] > buy){
				vector<int> rest(prices.begin() + i, prices.end());
				maxPro = max(maxPro, prices[i] - buy + maxProfit(rest));
			}
		}

		return maxPro;
	}

	int maxProfit2(vector<int>& prices){
		if (prices.size() < 2) return 0;
		int maxPro = 0;
		int buy = INT_MAX, right = 1;
		for (int i = 0; i < prices.size(); i++){
			if (buy>prices[i]) buy = prices[i];
			if (prices[i] > buy && ((i < prices.size() - 1 && prices[i + 1] <= prices[i]) || i == prices.size()-1) ){
				maxPro += prices[i] - buy;
				buy = INT_MAX;
			}
		}

		return maxPro;
	}
};

int main(void){
	vector<int> prices = { 1,4,3,2 };

	Solution model;
	int result = model.maxProfit2(prices);

	return 0;
}