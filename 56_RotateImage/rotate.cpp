class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return;
		int top = 0;
		int left = 0;
		int right = matrix.size() - 1;
		int bottom = matrix.size() - 1;
		int n = matrix.size();
		while (n > 1){
			for (int i = 0; i < n - 1; i++){
				int tmp = matrix[top][left + i];
				matrix[top][left + i] = matrix[bottom - i][left];
				matrix[bottom - i][left] = matrix[bottom][right - i];
				matrix[bottom][right - i] = matrix[top + i][right];
				matrix[top + i][right] = tmp;
			}
			top++;
			bottom--;
			left++;
			right--;
			n -= 2;
		}

	}
};