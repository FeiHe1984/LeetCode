class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		deque<int> index;
		vector<int> ans;
		if (size == 0) return ans;
		int k = size;

		for (int i = 0; i < num.size(); ++i){
			while (!index.empty() && num[i] >= num[index.back()]) index.pop_back();
			index.push_back(i);

			if (i - k + 1 >= 0) ans.push_back(num[index.front()]);
			if (i - k + 1 >= index.front()) index.pop_front();
		}
		return ans;
	}
};