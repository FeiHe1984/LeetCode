class Solution {
public:
	int numDistinct(string S, string T) {
		int dp[S.length() + 1][T.length() + 1];
		for (int i = 0; i <= S.length(); i++){
			for (int j = 0; j <= T.length(); j++){
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i <= S.length(); i++){
			dp[i][0] = 1;
		}

		for (int i = 1; i <= S.length(); i++){
			for (int j = 1; j <= T.length(); j++){
				if (S[i - 1] == T[j - 1]){
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				}
				else{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[S.length()][T.length()];
	}
};