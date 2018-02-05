class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		string s;
		map<string, int> anagram;
		vector<string> res;
		for (int i = 0; i< strs.size(); i++)
		{
			s = strs[i];
			sort(s.begin(), s.end());
			if (anagram.find(s) == anagram.end())
				anagram[s] = i;//把s映射到数字i  
			else
			{
				if (anagram[s] >= 0)
				{
					res.push_back(strs[anagram[s]]);//如果当前数字上面是i》＝0  
					//那就得把这个数字代表的那个str放进去  
					anagram[s] = -1;
				}
				//如果找到了，但是小于0，证明当前位置上这个已经放进去了，我们要做的就是把  
				//现在str［i］放进去就好啦  
				res.push_back(strs[i]);
			}
		}
		return res;
	}
};