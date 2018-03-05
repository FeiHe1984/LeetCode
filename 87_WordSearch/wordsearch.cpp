class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.size() == 0) return false;
		vector<vector<bool> > used;
		for (int i = 0; i < board.size(); ++i) {
			int nNumberOfCols = board[i].size();
			used.push_back(vector<bool>());
			for (int j = 0; j < nNumberOfCols; ++j) {
				used[i].push_back(false);
			}
		}

		for (int row = 0; row < board.size(); row++){
			for (int col = 0; col < board[0].size(); col++){
				if (existHelper(board, used, word, 0, col, row))
					return true;
			}
		}
		return false;
	}

	bool existHelper(vector<vector<char> > &board, vector<vector<bool> > &used, string &word, int idx, int col, int row){
		if (idx == word.length()) return true;
		if (row < 0 || row >= board.size() || col <0 || col >= board[0].size()) return false;
		if (used[row][col] == true || board[row][col] != word[idx]) return false;
		used[row][col] = true;

		bool exist = existHelper(board, used, word, idx + 1, col + 1, row);
		if (exist) return true;

		exist = existHelper(board, used, word, idx + 1, col - 1, row);
		if (exist) return true;

		exist = existHelper(board, used, word, idx + 1, col, row + 1);
		if (exist) return true;

		exist = existHelper(board, used, word, idx + 1, col, row - 1);
		if (exist) return true;

		used[row][col] = false;
		return false;
	}
};