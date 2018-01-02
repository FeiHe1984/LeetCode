class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> book;
		int i, Max = 0, pre = -1;
		for (i = 0; i<s.length(); i++) book[s[i]] = -1;
		for (i = 0; i<s.length(); i++)
		{
			pre = max(pre, book[s[i]]);
			Max = max(Max, i - pre);
			book[s[i]] = i;
		}
		return Max;
	}
};