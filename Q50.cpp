#include<vector>
using namespace std;

class Solution {
public:
	double sqr(double a){ return a*a; }
	double myPow(double x, int n) {
		if (n == 0) return 1;
		int flag = n % 2;
		if (n > 0){
			n = n >> 1;
			return flag ? sqr(myPow(x, n))*x : sqr(myPow(x, n));
		}			
		else{
			unsigned int nn = -n;
			nn = nn >> 1; n = nn;
			return flag ? sqr(myPow(x, -n)) / x : sqr(myPow(x, -n));
		}
	}
};

int main(void){
	double x = 2.0;
	int n = -2;

	Solution model;
	double result = model.myPow(x, n);

	return 0;
}