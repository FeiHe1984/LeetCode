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
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> res;
		if (intervals.empty()) return res;
		int n = intervals.size();
		int start[n];
		int end[n];

		for (int i = 0; i < intervals.size(); i++){
			start[i] = intervals[i].start;
			end[i] = intervals[i].end;
		}

		sort(start, start + n);
		sort(end, end + n);

		int i = 0;
		while (i < n){
			int st = start[i];
			while (i < n - 1 && start[i + 1] <= end[i]) i++;
			int ed = end[i];
			Interval in(st, ed);
			res.push_back(in);
			i++;
		}
		return res;
	}
};