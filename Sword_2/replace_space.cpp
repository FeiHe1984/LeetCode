class Solution {
public:
	void replaceSpace(char *str, int length) {
		// Write your code here
		if (length == 0) {
			return;
		}
		int newLength = length;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ') {
				newLength += 2;
			}
		}
		int j = length - 1;
		for (int i = newLength - 1; i >= 0;) {
			if (str[j] == ' ') {
				str[i--] = '0';
				str[i--] = '2';
				str[i--] = '%';
			}
			else {
				str[i--] = str[j];
			}
			j -= 1;
		}
	}
};