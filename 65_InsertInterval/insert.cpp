/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;

		int i = 0;
		int n = intervals.size();
		int n_start = newInterval.start;
		int n_end = newInterval.end;

		while (i < n && intervals[i].end < newInterval.start){
			res.push_back(intervals[i]);
			i++;
		}

		if (i == n){
			res.push_back(newInterval);
			return res;
		}

		n_start = min(intervals[i].start, newInterval.start);
		while (i <n && intervals[i].start <= newInterval.end){
			n_end = max(newInterval.end, intervals[i].end);
			i++;
		}
		Interval in(n_start, n_end);
		res.push_back(in);
		while (i < n){
			res.push_back(intervals[i++]);
		}
		return res;
	}
};