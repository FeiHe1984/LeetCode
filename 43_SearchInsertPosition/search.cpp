class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (A == NULL || n == 0) return 0;
		int start = 0;
		int end = n - 1;
		while (start + 1 < end){
			int mid = start + (end - start) / 2;
			if (A[mid] < target) start = mid;
			else if (A[mid] > target) end = mid;
			else return mid;
		}
		if (A[end] < target) return end + 1;
		else if (A[start] >= target) return start;
		else return end;

	}
};