#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto it = tokens.begin(); it != tokens.end(); it++) {
			if (isOperand(*it)) {
				int tmp1 = s.top();
				s.pop();
				int tmp2 = s.top();
				s.pop();

				int res = opend(tmp1, *it, tmp2);
				s.push(res);
			}
			else {
				s.push(stoi(*it));
			}
		}
		return s.top();
	}

	bool isOperand(string i) {
		if (i == "+" || i == "-" || i == "*" || i == "/")
			return true;
		else
			return false;
	}

	int opend(int tmp1, string ope, int tmp2) {
		int res = 0;
		switch (ope.c_str()[0]) {
		case '+': {res = tmp2+tmp1; break; }
		case '-': {res = tmp2-tmp1; break; }
		case '*': {res = tmp2*tmp1; break; }
		case '/': {res = tmp2/tmp1; break; }
		default: break;
		}
		return res;
	}
};

int main(void) {
	vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };

	Solution mode;
	int res = mode.evalRPN(tokens);

	return 0;
}