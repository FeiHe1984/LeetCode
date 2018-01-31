class Solution {
public:
	int trap(int A[], int n) {
		if (n <= 2) return 0;
		int lefttop = A[0], righttop = A[n - 1];
		int i = 1, j = n - 2;
		int sums = 0;
		while (i <= j) {
			if (lefttop > righttop) {
				sums += max(0, righttop - A[j]);
				righttop = max(righttop, A[j]);
				--j;
			}
			else {
				sums += max(0, lefttop - A[i]);
				lefttop = max(lefttop, A[i]);
				++i;
			}
		}
		return sums;
	}
};