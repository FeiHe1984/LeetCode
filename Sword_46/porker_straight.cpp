class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5) return false;
		sort(numbers.begin(), numbers.end());
		int cnt0 = 0, cntNeed = 0;
		for (int i = 0; i < 5; i++) {
			if (numbers[i] == 0) {
				++cnt0;
			}
			else if (i + 1 < 5) {
				if (numbers[i + 1] == numbers[i]) return false;
				cntNeed += numbers[i + 1] - numbers[i] - 1;
			}
		}
		if (cntNeed > cnt0) return false;
		return true;
	}
};