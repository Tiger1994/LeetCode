#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1, v2;
		v1 = convert(version1);
		v2 = convert(version2);
		for (decltype(v1.size()) i = 0; i < v1.size() && i<v2.size(); i++) {
			if (v1[i] > v2[i]) return 1;
			else if (v1[i] < v2[i]) return -1;
			else continue;
		}
		return 0;
	}

	vector<int> convert(string str) {
		string tmp;
		vector<int> res;
		for (auto i : str) {
			if (i == '.') {
				int i = atoi(tmp.c_str());
				res.push_back(i);
				tmp = "";
			}
			else {
				tmp += i;
			}
		}
		res.push_back(atoi(tmp.c_str()));
		while (res.size() < 4) res.push_back(0);
		return res;
	}

	int compareVersion2(string version1, string version2) {
		decltype(version1.size()) i, j, m, n;
		i = 0, j = 0, m = version1.size(), n = version2.size();
		while (i < m || j < n) {
			int num1 = 0, num2 = 0;
			while (i < m && version1[i] != '.') {
				num1 += num1 * 10 + (version1[i] - '0');
				i++;
			}
			while (j < n && version2[j] != '.') {
				num2 = num2 * 10 + (version2[j] - '0');
				j++;
			}
			i++, j++;
			if (num1 > num2) return 1;
			if (num1 < num2) return -1;
		}
		return 0;
	}
};

int main(void) {
	string v1 = "123";
	string v2 = "1.000000000000000000000010";
	Solution mode;
	int res = mode.compareVersion2(v1, v2);
	return 0;
}