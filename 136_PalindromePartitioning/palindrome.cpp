class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		if (s.empty()) return res;
		vector<string> path;

		helper(res, path, s);
		return res;
	}

	void helper(vector<vector<string>>& res, vector<string>& path, string s){
		if (s.length() == 0){
			res.push_back(path);
			return;
		}

		for (int i = 0; i < s.length(); i++){
			if (isPalindrome(s.substr(0, i + 1))){
				path.push_back(s.substr(0, i + 1));
				helper(res, path, s.substr(i + 1));
				path.pop_back();
			}
		}
	}

	bool isPalindrome(string s){
		for (int i = 0; i < s.length() / 2; i++){
			if (s[i] != s[s.length() - i - 1]){
				return false;
			}
		}
		return true;
	}
};