class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> lefts;
		int max_len = 0, match_pos = -1;

		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '(')
				lefts.push(i);
			else{
				if (lefts.empty())
					match_pos = i;
				else{
					lefts.pop();
					if (lefts.empty())
						max_len = max(max_len, i - match_pos);
					else
						max_len = max(max_len, i - lefts.top());
				}
			}
		}
		return max_len;
	}
};