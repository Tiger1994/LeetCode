#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> nums;
		int i = 0, j = 0;
		while(i < m && j < n) {
			if (nums1[i] <= nums2[j]){
				nums.push_back(nums1[i]); i++;
			}
			else{
				nums.push_back(nums2[j]); j++;
			}
		}
		if (j < n) nums.insert(nums.end(), nums2.begin() + j, nums2.begin()+n);
		else if(i < m) nums.insert(nums.end(), nums1.begin() + i, nums1.begin()+m);
		nums1 = nums;
	}

	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n){
		m--; n--;
		for (int i = m + n + 1; i >= 0; i--){
			if (m >= 0 && n >= 0 && nums1[m] >= nums2[n]) nums1[i] = nums1[m--];
			else if (m >= 0 && n >= 0 && nums1[m] < nums2[n]) nums1[i] = nums2[n--];
			else if (m >= 0) nums1[i] = nums1[m--];
			else if (n >= 0) nums1[i] = nums2[n--];
		}
	}
};

int main(void){
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };

	Solution model;
	model.merge2(nums1, 3, nums2, 3);

	return 0;
}