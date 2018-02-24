class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;

		int current = 2;
		int prev = 1;
		for (int i = 3; i <= n; i++){
			current = current + prev;
			prev = current - prev;
		}
		return current;
	}
};