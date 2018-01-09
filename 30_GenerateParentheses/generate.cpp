class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		helper("", res, n, 0, 0);
		return res;
	}
	void helper(string curr, vector<string> &res, int n, int left, int right){
		if (right == n){
			res.push_back(curr);
			return;
		}
		if (left < n){
			helper(curr + "(", res, n, left + 1, right);
		}
		if (right < left){
			helper(curr + ")", res, n, left, right + 1);
		}
	}
};