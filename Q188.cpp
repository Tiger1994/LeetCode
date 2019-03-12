#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		if (k >= prices.size()) return helper(prices);
		vector<int> g(k + 1, 0);
		vector<int> l(k + 1, 0);
		for (int i = 0; i < prices.size() - 1; i++) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 1; --j) {
				l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
				g[j] = max(g[j], l[j]);
			}
		}
		return g.back();
	}
	int helper(vector<int> &prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); ++i) {
			int tmp = prices[i] - prices[i - 1];
			if (tmp > 0) res += tmp;
		}
		return res;
	}
};

int main(void) {
	vector<int> prices = { 3,2,6,5,0,3 };
	int k = 2;
	Solution mode;
	int res = mode.maxProfit(k ,prices);
	return 0;
}