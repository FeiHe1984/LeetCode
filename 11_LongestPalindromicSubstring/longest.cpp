class Solution {
public:
	string longestPalindrome(string s) {
		int startIdx = 0, left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == s[i + 1]){
				left = i;
				right = i + 1;
				searchPalindrome(s, left, right, startIdx, len);
			}
			left = right = i;
			searchPalindrome(s, left, right, startIdx, len);
		}
		if (len == 0) len = s.size();
		return s.substr(startIdx, len);
	}
	void searchPalindrome(string s, int left, int right, int& startIdx, int &len){
		int step = 1;
		while ((left - step) >= 0 && (right + step) < s.size()){
			if (s[left - step] != s[right + step]) break;
			++step;
		}
		int wide = right - left + 2 * step - 1;
		if (len < wide){
			len = wide;
			startIdx = left - step + 1;
		}
	}
};