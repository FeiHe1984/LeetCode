class Solution {
public:
	string getPermutation(int n, int k) {
		k--;
		vector<int> nums;
		for (int i = 1; i <= n; i++){
			nums.push_back(i);
		}
		int fac = 1;
		for (int i = 2; i < n; i++){
			fac *= i;
		}
		string res;
		int round = n - 1;
		while (round >= 0){
			int index = k / fac;
			k %= fac;
			res += nums[index] + '0';
			nums.erase(nums.begin() + index);
			if (round){
				fac /= round;
			}
			round--;
		}
		return res;
	}
};