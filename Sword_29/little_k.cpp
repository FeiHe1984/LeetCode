class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len) return vector<int>();

		multiset<int, greater<int> > leastNums;
		vector<int>::iterator vec_it = input.begin();
		for (; vec_it != input.end(); vec_it++)
		{
			if (leastNums.size()<k)
				leastNums.insert(*vec_it);
			else
			{
				multiset<int, greater<int> >::iterator greatest_it = leastNums.begin();
				if (*vec_it<*(leastNums.begin()))
				{
					leastNums.erase(greatest_it);
					leastNums.insert(*vec_it);
				}
			}
		}

		return vector<int>(leastNums.begin(), leastNums.end());
	}
};