class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> myset(num.begin(), num.end());
		int res = 1;
		for (int current : num)
		{
			if (myset.find(current) == myset.end()) continue;

			myset.erase(current);
			int prev = current - 1, post = current + 1;
			while (myset.find(prev) != myset.end())
			{
				myset.erase(prev--);
			}
			while (myset.find(post) != myset.end())
			{
				myset.erase(post++);
			}
			res = max(res, post - prev - 1);
		}

		return res;
	}

};