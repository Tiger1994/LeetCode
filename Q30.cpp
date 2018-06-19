#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	bool isSubstring_1(string s, vector<string>& words){
		if (words.size() == 0) return true;
		for (int i = 0; i < words.size(); i++){
			if (s[0] == words[i][0]){
				int j = 0;
				while (j < words[i].size() && j < s.size() && words[i][j] == s[j]) j++;
				if (j == words[i].size()){
					string temp = s;
					temp.erase(0, j);
					vector<string> temp_words = words;
					temp_words.erase(temp_words.begin() + i);
					return this->isSubstring_1(temp, temp_words);
				}
			}
		}

		return false;
	}

	vector<int> findSubstring_1(string s, vector<string>& words) {
		vector<int> result;
		if (words.size() == 0 || s.size() == 0) return result;

		for (int i = 0; i < s.size(); i++){
			string temp = s;
			temp.erase(0, i);
			if (this->isSubstring_1(temp, words)) result.push_back(i);
		}

		return result;
	}

	vector<int> findSubstring_2(string s, vector<string>& words) {
		vector<int> result;
		if (words.size() == 0 || s.size() == 0) return result;

		map<string, int> word_map;
		int word_len = words[0].size();
		for (int i = 0; i < words.size(); i++){
			if (word_map.find(words[i]) == word_map.end()) word_map.insert(make_pair(words[i], 1));
			else word_map[words[i]] += 1;
		}

		for (int i = 0; i < word_len; i++){
			int left = i, right = i+word_len;
			map<string, int> curr_map;
			while (right <= s.size()){
				string temp_word = s.substr(right - word_len, word_len);
				if (word_map.find(temp_word) != word_map.end()){
					if (curr_map.find(temp_word) == curr_map.end()) curr_map.insert(make_pair(temp_word, 1));
					else curr_map[temp_word] += 1;

					if (curr_map[temp_word] <= word_map[temp_word]){
						if (right - left == words.size()*word_len){
							result.push_back(left);
							left = left+word_len, right = left + word_len;
							curr_map.clear();
							continue;
						}
						right += word_len;
					}
					else left = left+word_len, right = left + word_len, curr_map.clear();
				}
				else left = right, right = left + word_len, curr_map.clear();
			}
		}

		return result;
	}
};

int main(void){
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = { "word", "good", "best", "good" };

	Solution model;
	//vector<int> result = model.findSubstring_1(s, words);
	vector<int> result = model.findSubstring_2(s, words);

	return 0;
}