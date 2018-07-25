#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int maxPro = 0;
		for (int i = 0; i < prices.size()-1; i++){
			for (int j = i+1; j < prices.size(); j++){
				maxPro = max(maxPro, prices[j] - prices[i]);
			}
		}

		return maxPro;
	}

	int maxProfit2(vector<int>& prices){
		if (prices.size() <= 1) return 0;
		int maxPro = 0, left = 0, right = 1;
		while (right < prices.size()){
			if (prices[right] <= prices[left]){
				left = right;
				right++;
			}
			else{
				maxPro = max(maxPro, prices[right] - prices[left]);
				right++;
			}
		}

		return maxPro;
	}
};

int main(void){
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };

	Solution model;
	int result = model.maxProfit2(prices);

	return 0;
}