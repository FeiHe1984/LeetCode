class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();

		int res[row + 1];
		memset(res, 0, sizeof(int)*(row + 1));

		for (int i = row - 1; i >= 0; i--){
			for (int j = 0; j < triangle[i].size(); j++){
				res[j] = min(res[j], res[j + 1]) + triangle[i][j];
			}
		}
		return res[0];
	}
};