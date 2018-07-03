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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.size() == 0) return{ newInterval };
		int startPos, endPos;
		int left = 0, right = intervals.size() - 1;
		while (left < right){
			int mid = (left + right + 1) / 2;
			if (intervals[mid].start <= newInterval.start) left = mid;
			else right = mid - 1;
		}
		startPos = left;
		left = 0; right = intervals.size() - 1;
		while (left < right){
			int mid = (left + right) / 2;
			if (intervals[mid].end <= newInterval.end) left = mid + 1;
			else right = mid;
		}
		endPos = right;

		if (endPos - startPos == 2) intervals.erase(intervals.begin() + startPos + 1);
		else if (endPos - startPos > 2) intervals.erase(intervals.begin() + startPos + 1, intervals.begin() + endPos);
		if (intervals[startPos].start>newInterval.start) intervals.insert(intervals.begin() + startPos, newInterval);
		else intervals.insert(intervals.begin() + startPos + 1, newInterval);
		int idx = startPos;
		for (int i = startPos; i < startPos + 2 && idx<intervals.size() - 1; i++){
			if (intervals[idx].end >= intervals[idx + 1].start){
				intervals[idx].end = max(intervals[idx].end, intervals[idx + 1].end);
				intervals.erase(intervals.begin() + idx + 1);
			}
			else idx++;
		}

		return intervals;
	}
};

int main(void){
	vector<Interval> intervals = { Interval(1, 3), Interval(6, 7), Interval(8, 10), Interval(15, 18) };
	vector<Interval> intervals2 = { Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) };
	vector<Interval> intervals3 = { Interval(0, 0), Interval(1, 4), Interval(6, 8), Interval(9, 11) };
	Interval newInterval(4, 8);
	Interval newInterval3(0, 9);

	Solution model;
	vector<Interval> result = model.insert(intervals3, newInterval3);

	return 0;
}