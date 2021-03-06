class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();

		int dis[m + 1][n + 1];
		for (int i = 0; i <= m; i++) dis[i][0] = i;
		for (int j = 0; j <= n; j++) dis[0][j] = j;

		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				dis[i][j] = INT_MAX;
				if (word1[i - 1] == word2[j - 1]){
					dis[i][j] = min(dis[i - 1][j], dis[i][j - 1]) + 1;
					dis[i][j] = min(dis[i][j], dis[i - 1][j - 1]);
				}
				else{
					dis[i][j] = min(dis[i - 1][j], dis[i][j - 1]) + 1;
					dis[i][j] = min(dis[i][j], dis[i - 1][j - 1] + 1);
				}
			}
		}
		return dis[m][n];
	}
};