class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;

		for (int i = 0; i < s.length(); i++){
			for (int j = i; dp[i] && j< s.length(); ++j){
				if (dict.find(s.substr(i, j - i + 1)) != dict.end()){
					dp[j + 1] = true;
				}
			}
		}
		return dp[s.length()];
	}
};