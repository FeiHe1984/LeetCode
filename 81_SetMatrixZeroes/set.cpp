class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int row = matrix.size();
		int column = matrix[0].size();

		if (row == 0 || column == 0) return;

		bool firstRowZero = false;
		bool firstColZero = false;

		for (int i = 0; i < column; i++){
			if (matrix[0][i] == 0){
				firstRowZero = true;
				break;
			}
		}

		for (int i = 0; i < row; i++){
			if (matrix[i][0] == 0){
				firstColZero = true;
				break;
			}
		}

		for (int x = 1; x < column; x++){
			for (int y = 1; y < row; y++){
				if (matrix[y][x] == 0){
					matrix[y][0] = 0;
					matrix[0][x] = 0;
				}
			}
		}

		for (int i = 1; i < column; i++){
			if (matrix[0][i] == 0){
				for (int j = 1; j < row; j++) matrix[j][i] = 0;
			}
		}

		for (int i = 0; i < row; i++){
			if (matrix[i][0] == 0){
				for (int j = 1; j < column; j++) matrix[i][j] = 0;
			}
		}

		if (firstRowZero) for (int j = 0; j < column; j++) matrix[0][j] = 0;
		if (firstColZero) for (int j = 0; j < row; j++) matrix[j][0] = 0;
	}
};