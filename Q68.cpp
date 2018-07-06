#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int left = 0, right = 0, wordsLen = words.size();
		int lenCurr = 0, charLen = 0;
		while (right < wordsLen){
			lenCurr += words[right].size();
			if (lenCurr == maxWidth){
				string temp;
				for (int i = left; i < right; i++) temp += words[i] + " ";
				temp += words[right]; result.push_back(temp);
				right++; left = right; lenCurr = 0; charLen = 0;
			}
			else if (lenCurr > maxWidth){
				int wordsNum = right - left;
				if (wordsNum == 1){
					string temp = words[left];
					while (temp.size() < maxWidth) temp += " ";
					result.push_back(temp);
				}
				else{
					int spaceNum = maxWidth - charLen;
					int spaceEach = spaceNum / (wordsNum - 1);
					int remainder = spaceNum % (wordsNum - 1);
					string temp;
					for (int i = left; i < right-1; i++){
						temp += words[i];
						for (int j = 0; j < spaceEach; j++) temp += " ";
						if (i - left < remainder) temp += " ";
					}
					temp += words[right - 1];
					result.push_back(temp);
				}
				left = right; lenCurr = 0; charLen = 0;
			}
			else {
				charLen += words[right].size();
				lenCurr++; right++;				
			}
		}

		if (left < right){
			string temp;
			for (int i = left; i < right; i++){
				temp += words[i] + " ";
			}
			while (temp.size() < maxWidth) temp += " ";
			result.push_back(temp);
		}

		return result;
	}
};

int main(void){
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> words2 = { "What", "must", "be", "acknowledgment", "shall", "be" };
	vector<string> words3 = { "Science", "is", "what", "we", "understand", "well", "enough", "to", \
							  "explain", "to", "a", "computer.", "Art", "is", "everything", "else", 
							  "we", "do" };
	int maxWidth = 20;

	Solution model;
	vector<string> result = model.fullJustify(words3, maxWidth);

	return 0;
}