class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		vector<int> minCuts(len + 1);
		for (int i = 0; i <= len; i++)
			minCuts[i] = i - 1;

		bool dp[len][len];
		fill_n(&dp[0][0], len*len, false);

		for (int j = 1; j<len; j++)
		{
			for (int i = j; i >= 0; i--)
			{
				if (s[i] == s[j] && (dp[i + 1][j - 1] || (j - i)<2))
				{
					dp[i][j] = true;
					minCuts[j + 1] = min(minCuts[j + 1], 1 + minCuts[i]);
				}
			}
		}
		return minCuts[len];
	}
};