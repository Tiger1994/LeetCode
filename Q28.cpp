#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		if (haystack.size() == 0) return -1;

		for (int i = 0; i < haystack.size(); i++){
			int needle_idx = 0;
			int haystack_idx = i;
			while (haystack_idx < haystack.size() &&\
				   needle_idx < needle.size()     &&\
				   haystack[haystack_idx] == needle[needle_idx])
			{
				needle_idx++;
				haystack_idx++;
			}

			if (needle_idx == needle.size()) return i;
		}

		return -1;
	}
};

int main(void){
	string haystack = "mississippi";
	string needle = "mississippi";

	Solution model;
	int result = model.strStr(haystack, needle);

	return 0;
}