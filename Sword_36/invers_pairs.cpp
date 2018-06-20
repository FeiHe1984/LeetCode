class Solution {
public:
	int InversePairs(vector<int> data) {
		vector<int> temp(data);
		return merge(data, temp, 0, data.size() - 1);
	}

private:
	int MOD = 1000000007;
	int merge(vector<int> &data, vector<int> &temp, int start, int end)
	{
		if (start >= end)
			return 0;
		int mid = (start + end) >> 1;
		int ans = (merge(temp, data, start, mid) + merge(temp, data, mid + 1, end)) % MOD;
		int i = start, j = mid + 1, k = start;
		while (i <= mid && j <= end)
		{
			if (temp[i] <= temp[j])
				data[k++] = temp[i++];
			else
			{
				data[k++] = temp[j++];
				ans = (ans + mid - i + 1) % MOD;
			}
		}
		while (i <= mid)
			data[k++] = temp[i++];
		while (j <= end)
			data[k++] = temp[j++];
		return ans;
	}
};