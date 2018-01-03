class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<int> numSet(3);
		vector< vector<int> > r;

		sort(num.begin(), num.end());
		int sum;
		int len = num.size();

		for (int i = 0; i < len - 2; i++) {
			sum = 0 - num[i];
			numSet[0] = num[i];
			for (int j = i + 1, k = len - 1; j < k;){
				if (num[j] + num[k] == sum){
					numSet[1] = num[j++];
					numSet[2] = num[k--];
					r.push_back(numSet);

					while (j < k && num[j] == num[j - 1])
						j++;
					while (j < k && num[k] == num[k + 1])
						k--;
				}
				else if (num[j] + num[k] < sum)
					j++;
				else
					k--;
			}
			while (i < len - 2 && num[i + 1] == num[i])
				i++;
		}
		return r;
	}
};