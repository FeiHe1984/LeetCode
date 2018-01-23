class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> res(2, -1);
		if (A == NULL || n == 0) return res;
		int st_point = -1, end_point = -1;
		int start = 0, end = n - 1;

		while (start + 1 < end){
			int mid = start + (end - start) / 2;
			if (A[mid] >= target) end = mid;
			else start = mid;
		}
		if (A[start] == target) st_point = start;
		else if (A[end] == target) st_point = end;
		if (st_point == -1) return res;

		start = 0;
		end = n - 1;

		while (start + 1 < end){
			int mid = start + (end - start) / 2;
			if (A[mid] > target) end = mid;
			else start = mid;
		}
		if (A[end] == target) end_point = end;
		else if (A[start] == target) end_point = start;

		res[0] = st_point;
		res[1] = end_point;
		return res;
	}
};