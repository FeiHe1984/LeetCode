class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int sLen = strlen(s), sIndex = 0;
		int pLen = strlen(p), pIndex = 0;
		int ppre = 0, ipre = 0;
		bool flag = false;
		while (sIndex<sLen) {
			if (s[sIndex] == p[pIndex] || p[pIndex] == '?'){
				++sIndex, ++pIndex;
			}
			else if (p[pIndex] == '*'){    //��������¼*���濪ʼƥ�������
				ppre = ++pIndex;
				ipre = sIndex;            //��¼s�п�ʼ��*����ƥ�������
				flag = true;
			}
			else{
				if (flag){                //�޷�ƥ�䣬�ڳ���*�������*�ֲ�
					sIndex = ++ipre;
					pIndex = ppre;
				}
				else{
					return false;
				}
			}
		}
		while (p[pIndex] == '*') {          //��ʣ���*ƥ���
			++pIndex;
		}
		return pIndex == pLen&&sIndex == sLen;

	}
};