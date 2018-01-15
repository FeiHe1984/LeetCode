class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		int m = strlen(haystack);
		int n = strlen(needle);

		if (m < n) return nullptr;

		int diff = m - n + 1;

		for (int start = 0; start < diff; start++){
			int j = 0;
			for (; j < n; j++)
			{
				if (haystack[start + j] != needle[j]){
					break;
				}
			}
			if (j == n){
				return haystack + start;
			}

		}
		return nullptr;
	}
};