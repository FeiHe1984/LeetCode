class Solution {
public:
	int jump(int A[], int n) {
		if (A == NULL || n <= 1) return 0;
		int curMax = 0;
		int nextMax = 0;
		int step = 0;
		int index = 0;

		while (index <= curMax){
			while (index <= curMax){
				nextMax = max(nextMax, index + A[index]);
				index++;
			}
			curMax = nextMax;
			step++;
			if (curMax >= n - 1) return step;
		}
		return 0;
	}
};