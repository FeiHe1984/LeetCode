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
				anagram[s] = i;//��sӳ�䵽����i  
			else
			{
				if (anagram[s] >= 0)
				{
					res.push_back(strs[anagram[s]]);//�����ǰ����������i����0  
					//�Ǿ͵ð�������ִ�����Ǹ�str�Ž�ȥ  
					anagram[s] = -1;
				}
				//����ҵ��ˣ�����С��0��֤����ǰλ��������Ѿ��Ž�ȥ�ˣ�����Ҫ���ľ��ǰ�  
				//����str��i�ݷŽ�ȥ�ͺ���  
				res.push_back(strs[i]);
			}
		}
		return res;
	}
};