class Solution {
public:
	int maxSubArray(int A[], int n) {
		int maxToCurr = A[0];
		int sum = A[0];
		for (int i = 1; i < n; i++){
			maxToCurr = max(maxToCurr + A[i], A[i]);
			sum = max(sum, maxToCurr);
		}
		return sum;
	}
};