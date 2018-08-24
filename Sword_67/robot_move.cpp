class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		const int dirx[] = { 0, 0, 1, -1 };
		const int diry[] = { 1, -1, 0, 0 };

		queue<int> que;
		vector<bool> used(rows * cols, false);
		que.push(0 * cols + 0);
		used[0 * cols + 0] = true;
		int ret = 0;

		while (!que.empty()){
			auto now = que.front();
			que.pop();
			if (getSum(now / cols) + getSum(now % cols) <= threshold)
				ret++;
			else
				continue;
			for (int i = 0; i < 4; i++){
				int tx = now / cols + dirx[i], ty = now % cols + diry[i];
				if (tx >= 0 && tx < rows && ty >= 0 && ty < cols && !used[tx * cols + ty]){
					used[tx * cols + ty] = true;
					que.push(tx * cols + ty);
				}
			}

		}
		return ret;
	}
private:
	int getSum(int x){
		int ret = 0;
		for (; x; ret += x % 10, x /= 10);
		return ret;
	}
};