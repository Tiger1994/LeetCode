#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	vector<string> split(const string s, char delim){
		stringstream ss(s);
		string item; vector<string> elems;
		while (getline(ss, item, delim)) elems.push_back(item);
		return elems;
	}

	string simplifyPath(string path) {
		string result;
		vector<string> elems = split(path, '/');
		int ignore = 0;
		for (int i = elems.size() - 1; i >= 0; i--){
			if (elems[i] == "" || elems[i] == ".") continue;
			if (elems[i] == ".."){
				ignore++; continue;
			}
			if (ignore > 0){
				ignore--; continue;
			}
			if (!result.size()) result = "/" + elems[i];
			else result = "/" + elems[i] + result;
		}

		return result.size() ? result : "/";
	}

	string simplifyPath2(string path){
		string result;
		int left = path.size() - 1, right = path.size();
		int ignore = 0;
		while (left >= 0){
			if (path[left] == '/'){
				string elem = path.substr(left+1, right - left-1);
				if (elem == "" || elem == "."){
					left--; right = left+1; continue;
				}
				if (elem == ".."){
					ignore++; left--; right = left+1; continue;
				}
				if (ignore > 0){
					ignore--; left--; right = left+1; continue;
				}
				if (!result.size()) result = "/" + elem;
				else result = "/" + elem + result;
				left--; right = left + 1;
			}
			else left--;
		}

		return result;
	}
};

int main(void){
	string path = "/home/";
	string path2 = "/a/./b/../../c/";
	string path3 = "/../";
	string path4 = "/home//foo/";
	string path5 = "/...";

	Solution model;
	string result = model.simplifyPath2(path2);

	return 0;
}