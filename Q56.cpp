#include<vector>
#include<algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool cmp(Interval a, Interval b){
		return a.start < b.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp);

		int i = 0;
		while (i < intervals.size() - 1){
			if (intervals[i].end >= intervals[i+1].start){
				intervals[i].end = max(intervals[i + 1].end, intervals[i].end);
				intervals.erase(intervals.begin() + i + 1);
			}
			else i++;
		}

		return intervals;
	}
};

int main(void){
	vector<Interval> intervals = { Interval(2, 6), Interval(1, 3), Interval(8, 10), Interval(15, 18) };
	vector<Interval> intervals2 = { Interval(1, 4), Interval(2, 3)};

	Solution model;
	vector<Interval> result = model.merge(intervals2);

	return 0;
}