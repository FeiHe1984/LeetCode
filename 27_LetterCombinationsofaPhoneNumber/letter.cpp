class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		string strs[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		RecursionMethod(strs, digits, result, "");
		return result;
	}
	void RecursionMethod(string *strs, string digits, vector<string> &result, string temp)
	{
		if (digits.length() == 0)
		{
			result.push_back(temp);
			return;
		}
		for (int i = 0; i<strs[digits[0] - '2'].length(); i++)
		{
			temp += strs[digits[0] - '2'][i];
			RecursionMethod(strs, digits.substr(1, digits.length() - 1), result, temp);
			temp = temp.substr(0, temp.length() - 1);
		}
	}
};