class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;

		int startRow = 0;
		int endRow = matrix.size() - 1;
		int endCol = matrix[0].size() - 1;
		int row = -1;

		while (startRow + 1 < endRow){
			int mid = startRow + (endRow - startRow) / 2;
			if (matrix[mid][endCol] < target) startRow = mid;
			else endRow = mid;
		}
		if (matrix[startRow][endCol] >= target) row = startRow;
		else if (matrix[endRow][endCol] >= target) row = endRow;
		else return false;

		int start = 0;
		int end = endCol;
		while (start + 1 < end){
			int mid = start + (end - start) / 2;
			if (matrix[row][mid] < target) start = mid;
			else end = mid;
		}
		if (matrix[row][start] == target || matrix[row][end] == target) return true;
		else return false;

	}
};