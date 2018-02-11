class Solution {
public:
	bool canJump(int A[], int n) {
		if (n < 2) return true;
		int reach = 0, i = 0;
		for (i = 0; i < n && i <= reach; i++){
			reach = max(A[i] + i, reach);
			if (reach >= n - 1) return true;
		}
		return false;
	}
};