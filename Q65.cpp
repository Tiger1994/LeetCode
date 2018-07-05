#include<string>
using namespace std;

class Solution {
public:
	bool isDigit(char s){
		return (s <= '9' && s >= '0');}

	bool isSpace(char s){
		return s == ' ';}

	bool isSignal(char s){
		return s == '+' || s == '-';}

	bool isE(char s){
		return s == 'e';}

	bool isDot(char s){
		return s == '.';}

	bool isNumber(string s) {
		bool hasDot = false, hasE = false;
		while (s.size() && isSpace(s[0])) s.erase(0, 1);
		if (!s.size()) return false;

		if (isSignal(s[0])) s.erase(0, 1);
		int idx = 0;
		while (idx < s.size()){
			if (isDot(s[idx])){
				if (hasDot || hasE) return false;
				if (idx == 0 && !isDigit(s[idx+1])) return false;
				hasDot = true; idx++; continue;}
			else if (isE(s[idx])){
				if (idx == 0 || hasE) return false;
				if (isSignal(s[++idx])) idx++;
				if (!isDigit(s[idx++])) return false;
				hasE = true; continue;}
			else if (isSpace(s[idx])){
				while (idx < s.size()){
					if (!isSpace(s[idx])) return false;
					idx++;}
				return true;}

			else if (!isDigit(s[idx++])) return false;}

		return true;}};

int main(void){
	string s = "0";
	string s2 = " 0.1 ";
	string s3 = "abc";
	string s4 = "1 a";
	string s5 = "2e10";
	string s6 = ".";
	string s7 = "3.";
	string s8 = ". ";
	string s9 = "0e ";
	string s10 = ".1";
	string s11 = "e9";
	string s12 = "-1.";

	Solution model;
	bool result = model.isNumber(s12);

	return 0;}