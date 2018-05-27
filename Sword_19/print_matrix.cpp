class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		if (matrix.empty()) return res;

		int row = matrix.size();
		int column = matrix[0].size();
		int start = 0;

		while ((column > start * 2) && (row > start * 2)){
			int endX = column - 1 - start;
			int endY = row - 1 - start;

			for (int i = start; i <= endX; ++i){
				int number = matrix[start][i];
				res.push_back(number);
			}

			if (start < endY){
				for (int i = start + 1; i <= endY; ++i){
					int number = matrix[i][endX];
					res.push_back(number);
				}
			}

			if (start < endX && start < endY){
				for (int i = endX - 1; i >= start; --i){
					int number = matrix[endY][i];
					res.push_back(number);
				}
			}

			if (start < endX && start < endY - 1){
				for (int i = endY - 1; i >= start + 1; --i){
					int number = matrix[i][start];
					res.push_back(number);
				}
			}
			++start;
		}
		return res;
	}
};