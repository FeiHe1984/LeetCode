class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;

		for (int i = 1; i <= rowIndex + 1; i++){
			vector<int> now;
			now.push_back(1);
			for (int j = 1; j < i - 1; j++){
				int preVal = res.at(j - 1);
				int nowVal = res.at(j);
				now.push_back(preVal + nowVal);
			}
			if (i > 1) now.push_back(1);

			res = now;
		}
		return res;

	}
};