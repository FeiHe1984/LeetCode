class Solution {
public:
	bool search(int A[], int n, int target) {
		if (A == NULL || n == 0) return false;

		int start = 0, end = n - 1;

		int mid;
		while (start + 1 < end){
			mid = start + (end - start) / 2;
			if (A[mid] == target) return true;
			if (A[mid] > A[start]){
				if (A[mid] >= target && A[start] <= target) end = mid;
				else start = mid;
			}
			else if (A[mid] < A[start]){
				if (A[mid] <= target && A[end] >= target) start = mid;
				else end = mid;
			}
			else start++;
		}

		if (A[start] == target || A[end] == target) return true;
		return false;

	}
};