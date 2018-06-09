#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> sums;
		while (!nums1.empty() && !nums2.empty()){
			int temp1 = nums1.back();
			int temp2 = nums2.back();
			if (temp1 > temp2){ 
				sums.push_back(temp1);
				nums1.pop_back();
			}
			else{ 
				sums.push_back(temp2);
				nums2.pop_back();
			}
			
			
		}

		vector<int> rest;
		if (!nums1.empty()){ rest = nums1; }
		else{ rest = nums2; }
		while (!rest.empty()){
			sums.push_back(rest.back());
			rest.pop_back();
		}

		int sums_len = sums.size();
		double result;
		if (sums_len % 2){
			int idx = (sums_len + 1) / 2;
			result = sums[idx-1];
		}
		else{
			int idx = sums_len / 2;
			result = double(sums[idx] + sums[idx - 1]) / 2;
		}

		return result;
	}
};

int main(void){
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums2.push_back(2);
	nums2.push_back(3);

	Solution model;
	double result = model.findMedianSortedArrays(nums1, nums2);

	return 0;
}