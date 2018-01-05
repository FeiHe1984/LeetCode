class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		set<vector<int>> res;
		sort(num.begin(), num.end());

		for (int i = 0; i < int(num.size() - 3); ++i){
			for (int j = i + 1; j < int(num.size() - 2); ++j){
				int left = j + 1, right = num.size() - 1;
				while (left < right){
					int sum = num[i] + num[j] + num[left] + num[right];
					if (sum == target){
						vector<int> out;
						out.push_back(num[i]);
						out.push_back(num[j]);
						out.push_back(num[left]);
						out.push_back(num[right]);
						res.insert(out);
						++left; --right;
					}
					else if (sum < target) ++left;
					else --right;
				}
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
};