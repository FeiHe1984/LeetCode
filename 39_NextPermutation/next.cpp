class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		int index = nums.size() - 1;
		while (nums[index] <= nums[index - 1]) {
			--index;
		}
		if (index == 0) {
			sort(nums.begin(), nums.end());
			return;
		}

		int second = INT_MAX, secondIndex = INT_MAX;
		for (int i = nums.size() - 1; i >= index - 1; --i) {
			if (nums[i] > nums[index - 1]) {
				if (nums[i] < second) {
					second = nums[i];
					secondIndex = i;
				}
			}
		}
		int temp = nums[index - 1];
		nums[index - 1] = nums[secondIndex];
		nums[secondIndex] = temp;

		sort(nums.begin() + index, nums.end());
	}
};