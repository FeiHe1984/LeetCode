class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> cur(n, string(n, '.')); // ��ʼ�����̣����е�λ�ö�û�аڷŻʺ�
		dfs(res, cur, n, 0);
		return res;
	}

	void dfs(vector<vector<string>> &res, vector<string> &cur, int &n, int row) {
		if (row == n) { // �������������������̣������������Ľ������res�С�
			res.push_back(cur);
			return;
		}

		for (int j = 0; j < n; j++) {
			if (isValid(cur, n, row, j)) { // �ж���(row, j)���Ƿ���Է�һ���ʺ�
				cur[row][j] = 'Q'; // ������ԣ����һ���ʺ�
				dfs(res, cur, n, row + 1); // ��������һ����һ��λ�÷Żʺ�
				cur[row][j] = '.'; // ��Ϊ��Ҫ�ҵ����п��ܵ���������Ա�Ȼ��Ҫ��ÿһ�н��л��ˡ�ȥ�ж���һ�е���һ���Ƿ���ԷŻʺ�
			}
		}
	}

	bool isValid(vector<string> &cur, int &n, int row, int col) {
		// �����
		for (int i = 0; i < row; i++) {
			if (cur[i][col] == 'Q') {
				return false;
			}
		}
		// ��鷴б��
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (cur[i][j] == 'Q') {
				return false;
			}
		}
		// ���б��
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (cur[i][j] == 'Q') {
				return false;
			}
		}
		return true;

	}
};