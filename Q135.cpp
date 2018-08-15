#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int num = ratings.size();
		vector<int> candies(num, 1);
		for (int i = 0; i < num - 1; i++){
			if (ratings[i] < ratings[i + 1])
				candies[i + 1] = candies[i] + 1;
		}
		for (int i = num - 1; i > 0; i--){
			if (ratings[i - 1]>ratings[i])
				candies[i - 1] = candies[i] + 1;
		}

		int res = accumulate(candies.begin(), candies.end(), 0);
		return res;
	}
};

int main(void){
	vector<int> ratings = { 1, 2, 2 };

	Solution model;
	int res = model.candy(ratings);

	return 0;
}