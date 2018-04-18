class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.empty()) return;

		int m = board.size() - 1;
		int n = board[0].size() - 1;

		for (int i = 0; i <= m; i++){
			if (board[i][0] == 'O'){
				dfs(board, i, 0);
			}
			if (board[i][n] == 'O'){
				dfs(board, i, n);
			}
		}

		for (int i = 0; i <= n; i++){
			if (board[0][i] == 'O'){
				dfs(board, 0, i);
			}
			if (board[m][i] == 'O'){
				dfs(board, m, i);
			}
		}

		for (int i = 0; i <= m; i++){
			for (int j = 0; j <= n; j++){
				if (board[i][j] == 'O'){
					board[i][j] = 'X';
				}
				else if (board[i][j] == '1'){
					board[i][j] = 'O';
				}
			}
		}

	}

	void dfs(vector<vector<char>> &board, int i, int j){
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O'){
			return;
		}

		board[i][j] = '1';
		dfs(board, i, j + 1);
		dfs(board, i, j - 1);
		dfs(board, i + 1, j);
		dfs(board, i - 1, j);
	}
};