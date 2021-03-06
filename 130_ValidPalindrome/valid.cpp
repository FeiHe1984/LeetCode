class Solution {
public:

	bool isPalindrome(string s) {
		if (s.empty()) return true;
		int left = 0;
		int right = s.length() - 1;

		while (left < right){
			while (left<right && !isalnum(s[left])) ++left;
			while (left<right && !isalnum(s[right])) --right;
			if (left < right && tolower(s[left]) != tolower(s[right])) return false;

			++left;
			--right;
		}
		return true;
	}
};