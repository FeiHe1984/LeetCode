class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		dfs(board, 0, 0);
	}
	bool dfs(vector<vector<char>> &board, int i, int j)
	{
		if (j >= 9) return dfs(board, i + 1, 0);
		if (i == 9) return true;
		if (board[i][j] == '.')
		{
			for (int k = 1; k <= 9; k++)
			{
				board[i][j] = char(k + '0');
				if (isValid(board, i, j))
				{
					if (dfs(board, i, j + 1)) return true;
				}
				board[i][j] = '.';
			}
		}
		else return dfs(board, i, j + 1);
		return false;
	}
	bool isValid(vector<vector<char>> &board, int i, int j)//在board作为参数时，有&和没&，时间效率差别非常大！！！
	{
		for (int k = 0; k < 9; k++)
		{
			if (k != j&&board[i][j] == board[i][k]) return false;
		}
		for (int k = 0; k < 9; k++)
		{
			if (k != i&&board[i][j] == board[k][j]) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; row++)//(i,j)所在的小九宫格
		{
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; col++)
			{
				if ((row != i || col != j) && board[i][j] == board[row][col])
					return false;
			}
		}
		return true;
	}
};