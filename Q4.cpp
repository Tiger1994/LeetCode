#include<vector>
#include<algorithm>
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

	double findMedianSortedArrays_2(vector<int>& nums1, vector<int>& nums2){
		vector<int> A = nums1, B = nums2;
		int m = A.size(), n = B.size();
		if (m > n){
			A = nums2;
			B = nums1;
			m = A.size();
			n = B.size();
		}
		if (m == 0){
			if (n % 2) return B[n / 2];
			else return double(B[n / 2] + B[n / 2 - 1]) / 2;
		}
		else if (m == 1){
			if ((m + n) % 2){
				if (A[0] >= B[n / 2 - 1] && A[0] <= B[n / 2]) return A[0];
				else if (A[0] < B[n / 2 - 1]) return B[n / 2-1];
				else return B[n / 2];
			}
			else if (n == 1) return double(A[0] + B[0]) / 2;
			else{
				if (A[0] <= B[n / 2 - 1]){
					return double(B[n / 2] + B[n / 2 - 1]) / 2;
				}
				else if (A[0] >= B[n / 2 + 1]){
					return double(B[n / 2] + B[n / 2 + 1]) / 2;
				}
				else{
					return double(A[0] + B[n / 2]) / 2;
				}
			}
		}

		int imin = 0, imax = m, halfLen = (m + n + 1)/2;
		while (imin <= imax){
			int i = (imin + imax) / 2;
			int j = halfLen - i;
			bool su1 = i == 0 || j == n || A[i - 1] <= B[j];
			bool su2 = m == 1 || j == 0 || i == m || B[j - 1] <= A[i];
			if (su1 && su2){
				double maxL, minR;
				if (m == 1) maxL = max(A[0], B[j - 1]);
				else if (i == 0) maxL = B[j - 1];
				else if (j == 0) maxL = A[i - 1];
				else maxL = max(A[i - 1], B[j - 1]);

				if ((m + n) % 2) return maxL;

				if (n == 1) minR = min(A[0], B[0]);
				else if (i == m) minR = B[j];
				else if (j == n) minR = A[i];
				else minR = min(A[i], B[j]);

				return (maxL + minR) / 2;
			}
			else if (i < m && B[j - 1] > A[i]) imin = i + 1;
			else if (i > 0 && A[i - 1] > B[j]) imax = i - 1;
		}
	}
};

int main(void){
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {3, 4, 5};

	Solution model;
	double result = model.findMedianSortedArrays_2(nums1, nums2);

	return 0;
}