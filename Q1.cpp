#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int num_len = nums.size();
		vector<int> result(2, -1);
		for (int i = 0; i < num_len; i++)
		{
			for (int j = 0; j < num_len; j++)
			{
				if (i != j)
				{
					if (nums[i] + nums[j] == target)
					{
						result[0] = i;
						result[1] = j;
						return result;
					}
				}
			}
		}
		return result;
	}
};

int main(void)
{
	vector<int> input(100);
	for (int i = 0; i < 100; i++)
	{
		input[i] = i;
	}
	vector<int> result;
	Solution model;
	result = model.twoSum(input, 50);
	cout << result[0] << '\n' << result[1];
	while (1);
	return 0;
}
