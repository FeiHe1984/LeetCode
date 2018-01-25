class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		bool used[9];
		for (int i = 0; i < 9; i++) {
			//先按行检查
			memset(used, 0, 9);
			for (int j = 0; j < 9; j++)
			if (!check(board[i][j], used))
				return false;
			//按列检查
			memset(used, 0, 9);
			for (int j = 0; j < 9; j++)
			if (!check(board[j][i], used))
				return false;
		}
		//从上到下，检查9方格
		for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++) {
			//按行，从左到右检查3个9方格；
			memset(used, 0, 9);
			for (int i = x * 3; i < x * 3 + 3; i++)
			for (int j = y * 3; j < y * 3 + 3; j++)
			if (!check(board[i][j], used))
				return false;

		}
		return true;
	}
	//private:
	//检查ch是否被使用，没用过返回true
	bool check(char ch, bool used[]) {
		if (ch == '.') return true;
		if (used[ch - '1'])
			return false;
		used[ch - '1'] = true;
		return true;
	}
};