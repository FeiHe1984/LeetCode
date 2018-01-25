class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		bool used[9];
		for (int i = 0; i < 9; i++) {
			//�Ȱ��м��
			memset(used, 0, 9);
			for (int j = 0; j < 9; j++)
			if (!check(board[i][j], used))
				return false;
			//���м��
			memset(used, 0, 9);
			for (int j = 0; j < 9; j++)
			if (!check(board[j][i], used))
				return false;
		}
		//���ϵ��£����9����
		for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++) {
			//���У������Ҽ��3��9����
			memset(used, 0, 9);
			for (int i = x * 3; i < x * 3 + 3; i++)
			for (int j = y * 3; j < y * 3 + 3; j++)
			if (!check(board[i][j], used))
				return false;

		}
		return true;
	}
	//private:
	//���ch�Ƿ�ʹ�ã�û�ù�����true
	bool check(char ch, bool used[]) {
		if (ch == '.') return true;
		if (used[ch - '1'])
			return false;
		used[ch - '1'] = true;
		return true;
	}
};