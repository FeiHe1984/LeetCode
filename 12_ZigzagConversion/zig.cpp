class Solution {
public:
	string convert(string s, int nRows) {
		int size = static_cast<int>(s.size());
		if (nRows <= 1 || nRows >= size){
			return s;
		}

		vector<string> rowString(nRows);
		int rowNum = 1;
		int flag = 1;
		for (int i = 0; i < size; i++){
			rowString[rowNum - 1] += s[i];
			if (rowNum == nRows){
				flag = -1;
			}
			if (rowNum == 1){
				flag = 1;
			}
			rowNum += flag;
		}
		string result;
		for (int i = 0; i < nRows; ++i){
			result += rowString[i];
		}
		return result;
	}
};