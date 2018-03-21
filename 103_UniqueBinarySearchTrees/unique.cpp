class Solution {
public:
	int numTrees(int n) {
		if (n <= 0) return 0;
		int nums[n + 1];
		memset(nums, 0, sizeof(nums));

		nums[0] = 1;
		nums[1] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= i; j++){
				nums[i] += (nums[i - j] * nums[j - 1]);
			}
		}
		return nums[n];
	}
};
